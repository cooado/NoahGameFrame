// -------------------------------------------------------------------------
//    @FileName			:		NFCWSNoTLS.cpp
//    @Author			:		Stone.xin
//    @Date				:		2016-12-22
//    @Module			:		NFCWSNoTLS
// -------------------------------------------------------------------------

#include "NFCWSNoTLS.h"
#include <string.h>
#include <atomic>

bool NFCWSNoTLS::Execute()
{
	if (mbWorking)
	{
		ExecuteClose();
		m_EndPoint.poll_one();
	}
	return false;
}

int NFCWSNoTLS::Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount)
{
	if (mbWorking)
	{
		return 1;
	}

	mnPort = nPort;
	mnMaxConnect = nMaxClient;
	mnCpuCount = nCpuCount;

	m_EndPoint.init_asio();

	m_EndPoint.set_message_handler(std::bind(
		&NFCWSNoTLS::OnMessageHandler, this,
		std::placeholders::_1, std::placeholders::_2
		));

	m_EndPoint.set_open_handler(std::bind(
		&NFCWSNoTLS::OnOpenHandler, this,
		std::placeholders::_1));

	m_EndPoint.set_close_handler(std::bind(
		&NFCWSNoTLS::OnCloseHandler, this,
		std::placeholders::_1));

	m_EndPoint.set_fail_handler(std::bind(
		&NFCWSNoTLS::OnFailHandler, this,
		std::placeholders::_1));

	m_EndPoint.set_pong_handler(std::bind(
		&NFCWSNoTLS::OnPongHandler, this,
		std::placeholders::_1, std::placeholders::_2));

	m_EndPoint.set_interrupt_handler(std::bind(
		&NFCWSNoTLS::OnInterruptHandler, this,
		std::placeholders::_1));
	
	m_EndPoint.set_pong_timeout_handler(std::bind(
		&NFCWSNoTLS::OnPongTimeOutHandler, this,
		std::placeholders::_1, std::placeholders::_2));

	m_EndPoint.set_http_handler(std::bind(&NFCWSNoTLS::OnHttp, this, std::placeholders::_1));

	m_EndPoint.listen(nPort);
	m_EndPoint.start_accept();

	mbWorking = true;

	return 0;
}

bool NFCWSNoTLS::Final()
{
	CloseSocketAll();
	m_EndPoint.stop_listening();

	return true;
}

bool NFCWSNoTLS::SendMsgToAllClient(const char * msg, const uint32_t nLen)
{
	if (nLen <= 0)
	{
		return false;
	}

	session_list::iterator it = mmObject.begin();
	while (it!=mmObject.end())
	{
		WSObjectPtr pWSObject = it->second;
		if (pWSObject && !pWSObject->NeedRemove())
		{
			try
			{
				m_EndPoint.send(it->first, msg, nLen, websocketpp::frame::opcode::BINARY);
			}
			catch (websocketpp::exception& e)
			{
				std::cout<<"websocket exception: "<<e.what()<< " this conn will be removed." <<std::endl;
				RemoveConnection(it->first, NF_WS_EVENT_CLOSE);
			}
		}
		it++;
	}
	
	return true;
}

bool NFCWSNoTLS::SendMsgToClient(const char * msg, const uint32_t nLen, const std::vector<websocketpp::connection_hdl>& vList)
{
	for (auto vIt:vList)
	{
		auto pWSObject = GetNetObject(vIt);
		if (pWSObject && !pWSObject->NeedRemove())
		{
			try
			{
				m_EndPoint.send(vIt, msg, nLen, websocketpp::frame::opcode::BINARY);
				return true;
			}
			catch (websocketpp::exception& e)
			{
				std::cout << "websocket exception: " << e.what()<<" this conn will be removed." << std::endl;	
				RemoveConnection(vIt, NF_WS_EVENT_CLOSE);
			}
		}
	}
	return false;
}

bool NFCWSNoTLS::SendMsgToClient(const char * msg, const uint32_t nLen, websocketpp::connection_hdl hd)
{
	auto pWSObject = GetNetObject(hd);
	if (pWSObject && !pWSObject->NeedRemove())
	{
		try
		{
			m_EndPoint.send(hd, msg, nLen, websocketpp::frame::opcode::BINARY);
			return true;
		}
		catch (websocketpp::exception& e)
		{
			std::cout << "websocket exception: " << e.what()<<" this conn will be removed." << std::endl;
			RemoveConnection(hd, NF_WS_EVENT_CLOSE);
		}
	}
	return false;
}

bool NFCWSNoTLS::AddNetObject(websocketpp::connection_hdl hd,WSObjectPtr pWSObject)
{
	auto pObject = GetNetObject(hd);
	if (pObject)
	{
		return false;
	}
	mmObject.emplace(session_list::value_type(hd,pWSObject));
	return true;
}

WSObjectPtr NFCWSNoTLS::GetNetObject(websocketpp::connection_hdl hd)
{
	session_list::iterator it = mmObject.find(hd);
	if (it == mmObject.end())
	{
		return nullptr;
	}
	return it->second;
}

void NFCWSNoTLS::ExecuteClose()
{
	for(auto vIt : mvRemoveObject)
	{
		CloseObject(vIt);
	}
	mvRemoveObject.clear();
}

bool NFCWSNoTLS::CloseSocketAll()
{
	session_list::iterator it = mmObject.begin();
	while(it != mmObject.end())
	{
		mvRemoveObject.push_back(it->first);
		it++;
	}

	ExecuteClose();

	mmObject.clear();

	return true;
}

void NFCWSNoTLS::CloseObject(websocketpp::connection_hdl hd, int nCloseCode/* =1000 */, const std::string& strCloseReason/* ="" */)
{
	// close会抛异常，所以try-catch一下
	try{
		m_EndPoint.close(hd, nCloseCode, strCloseReason);
	}
	catch(websocketpp::exception e){
		std::cout<<"websocket exception when close object: " << e.what() << std::endl;
	}
}

void NFCWSNoTLS::OnMessageHandler(websocketpp::connection_hdl hd, NFWebSockConf::message_ptr msg)
{
	auto pObject = GetNetObject(hd);
	if (!pObject)
	{
		return;
	}

	if (mRecvCB)
	{
		mRecvCB(hd,msg->get_payload(), pObject);
	}
}

void NFCWSNoTLS::OnOpenHandler(websocketpp::connection_hdl hd)
{
	WSObjectPtr pWSObject(NF_NEW(WSObject));
	if (AddNetObject(hd,pWSObject))
	{
		if (mEventCB)
		{
			mEventCB(hd, NF_WS_EVENT_OPEN, pWSObject);
		}
	}
}

bool NFCWSNoTLS::RemoveConnection(websocketpp::connection_hdl hd, NF_WS_EVENT evt, int nCloseCode /* = 1000 */, const std::string& strCloseReason /* = "" */)
{
	session_list::iterator it = mmObject.find(hd);
	if (it != mmObject.end())
	{
		mvRemoveObject.push_back(hd);
        mmObject.erase(it);
		return true;
	}
	return false;
}

void NFCWSNoTLS::OnCloseHandler(websocketpp::connection_hdl hd)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_CLOSE);
	if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_CLOSE, pObject);
}

void NFCWSNoTLS::OnFailHandler(websocketpp::connection_hdl hd)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_FAIL);
    if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_FAIL, pObject);
}

void NFCWSNoTLS::OnInterruptHandler(websocketpp::connection_hdl hd)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_INTERRUPT);
    if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_INTERRUPT, pObject);
}

bool NFCWSNoTLS::OnPongHandler(websocketpp::connection_hdl hd, std::string str)
{
	return true;
}

void NFCWSNoTLS::OnPongTimeOutHandler(websocketpp::connection_hdl hd, std::string str)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_PONG_TIMEOUT);
    if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_PONG_TIMEOUT, pObject);
}

void NFCWSNoTLS::OnHttp(websocketpp::connection_hdl hdl) {
	NFWebSockConfNoTLS::connection_ptr con = m_EndPoint.get_con_from_hdl(hdl);

	con->set_body("Hello World!");
	con->set_status(websocketpp::http::status_code::ok);
}