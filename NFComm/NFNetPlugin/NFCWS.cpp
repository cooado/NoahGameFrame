// -------------------------------------------------------------------------
//    @FileName			:		NFCWS.cpp
//    @Author			:		Stone.xin
//    @Date				:		2016-12-22
//    @Module			:		NFCWS
// -------------------------------------------------------------------------

#include "NFCWS.h"
#include <string.h>
#include <atomic>

bool NFCWS::Execute()
{
	if (mbWorking)
	{
		ExecuteClose();
		m_EndPoint.poll_one();
	}
	return false;
}

int NFCWS::Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount)
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
		&NFCWS::OnMessageHandler, this,
		std::placeholders::_1, std::placeholders::_2
		));

	m_EndPoint.set_open_handler(std::bind(
		&NFCWS::OnOpenHandler, this,
		std::placeholders::_1));

	m_EndPoint.set_close_handler(std::bind(
		&NFCWS::OnCloseHandler, this,
		std::placeholders::_1));

	m_EndPoint.set_fail_handler(std::bind(
		&NFCWS::OnFailHandler, this,
		std::placeholders::_1));

	m_EndPoint.set_pong_handler(std::bind(
		&NFCWS::OnPongHandler, this,
		std::placeholders::_1, std::placeholders::_2));

	m_EndPoint.set_interrupt_handler(std::bind(
		&NFCWS::OnInterruptHandler, this,
		std::placeholders::_1));
	
	m_EndPoint.set_pong_timeout_handler(std::bind(
		&NFCWS::OnPongTimeOutHandler, this,
		std::placeholders::_1, std::placeholders::_2));

	m_EndPoint.set_http_handler(std::bind(&NFCWS::OnHttp, this, std::placeholders::_1));
	m_EndPoint.set_tls_init_handler(std::bind(&NFCWS::OnTlsInit, this, MOZILLA_INTERMEDIATE, std::placeholders::_1));

	m_EndPoint.listen(nPort);
	m_EndPoint.start_accept();

	mbWorking = true;

	return 0;
}

bool NFCWS::Final()
{
	CloseSocketAll();
	m_EndPoint.stop_listening();

	return true;
}

bool NFCWS::SendMsgToAllClient(const char * msg, const uint32_t nLen)
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

bool NFCWS::SendMsgToClient(const char * msg, const uint32_t nLen, const std::vector<websocketpp::connection_hdl>& vList)
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

bool NFCWS::SendMsgToClient(const char * msg, const uint32_t nLen, websocketpp::connection_hdl hd)
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

bool NFCWS::AddNetObject(websocketpp::connection_hdl hd,WSObjectPtr pWSObject)
{
	auto pObject = GetNetObject(hd);
	if (pObject)
	{
		return false;
	}
	mmObject.emplace(session_list::value_type(hd,pWSObject));
	return true;
}

WSObjectPtr NFCWS::GetNetObject(websocketpp::connection_hdl hd)
{
	session_list::iterator it = mmObject.find(hd);
	if (it == mmObject.end())
	{
		return nullptr;
	}
	return it->second;
}

void NFCWS::ExecuteClose()
{
	for(auto vIt : mvRemoveObject)
	{
		CloseObject(vIt);
	}
	mvRemoveObject.clear();
}

bool NFCWS::CloseSocketAll()
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

void NFCWS::CloseObject(websocketpp::connection_hdl hd, int nCloseCode/* =1000 */, const std::string& strCloseReason/* ="" */)
{
	// close会抛异常，所以try-catch一下
	try{
		m_EndPoint.close(hd, nCloseCode, strCloseReason);
	}
	catch(websocketpp::exception e){
		std::cout<<"websocket exception when close object: " << e.what() << std::endl;
	}
}

void NFCWS::OnMessageHandler(websocketpp::connection_hdl hd, NFWebSockConf::message_ptr msg)
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

void NFCWS::OnOpenHandler(websocketpp::connection_hdl hd)
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

bool NFCWS::RemoveConnection(websocketpp::connection_hdl hd, NF_WS_EVENT evt, int nCloseCode /* = 1000 */, const std::string& strCloseReason /* = "" */)
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

void NFCWS::OnCloseHandler(websocketpp::connection_hdl hd)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_CLOSE);
	if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_CLOSE, pObject);
}

void NFCWS::OnFailHandler(websocketpp::connection_hdl hd)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_FAIL);
    if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_FAIL, pObject);
}

void NFCWS::OnInterruptHandler(websocketpp::connection_hdl hd)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_INTERRUPT);
    if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_INTERRUPT, pObject);
}

bool NFCWS::OnPongHandler(websocketpp::connection_hdl hd, std::string str)
{
	return true;
}

void NFCWS::OnPongTimeOutHandler(websocketpp::connection_hdl hd, std::string str)
{
    auto pObject = GetNetObject(hd);
    if(!pObject)
        return;
	RemoveConnection(hd, NF_WS_EVENT_PONG_TIMEOUT);
    if(mEventCB)
        mEventCB(hd, NF_WS_EVENT_PONG_TIMEOUT, pObject);
}

void NFCWS::OnHttp(websocketpp::connection_hdl hdl) {
	NFWebSockConf::connection_ptr con = m_EndPoint.get_con_from_hdl(hdl);

	con->set_body("Hello World!");
	con->set_status(websocketpp::http::status_code::ok);
}

NFCWS::context_ptr NFCWS::OnTlsInit(tls_mode mode, websocketpp::connection_hdl hdl) {
	namespace asio = websocketpp::lib::asio;

	std::cout << "on_tls_init called with hdl: " << hdl.lock().get() << std::endl;
	std::cout << "using TLS mode: " << (mode == MOZILLA_MODERN ? "Mozilla Modern" : "Mozilla Intermediate") << std::endl;

	context_ptr ctx = websocketpp::lib::make_shared<asio::ssl::context>(asio::ssl::context::sslv23);

	try {
		if (mode == MOZILLA_MODERN) {
			// Modern disables TLSv1
			ctx->set_options(asio::ssl::context::default_workarounds |
							 asio::ssl::context::no_sslv2 |
							 asio::ssl::context::no_sslv3 |
							 asio::ssl::context::no_tlsv1 |
							 asio::ssl::context::single_dh_use);
		} else {
			ctx->set_options(asio::ssl::context::default_workarounds |
							 asio::ssl::context::no_sslv2 |
							 asio::ssl::context::no_sslv3 |
							 asio::ssl::context::single_dh_use);
		}
		ctx->set_password_callback(std::bind(&NFCWS::GetPassword, this));
		ctx->use_certificate_chain_file("../cert/fullchain.pem");
		ctx->use_private_key_file("../cert/privkey.pem", asio::ssl::context::pem);

		// Example method of generating this file:
		// `openssl dhparam -out dh.pem 2048`
		// Mozilla Intermediate suggests 1024 as the minimum size to use
		// Mozilla Modern suggests 2048 as the minimum size to use.
		ctx->use_tmp_dh_file("../cert/dh.pem");

		std::string ciphers;

		if (mode == MOZILLA_MODERN) {
			ciphers = "ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-DSS-AES128-GCM-SHA256:kEDH+AESGCM:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA256:DHE-RSA-AES256-SHA256:DHE-DSS-AES256-SHA:DHE-RSA-AES256-SHA:!aNULL:!eNULL:!EXPORT:!DES:!RC4:!3DES:!MD5:!PSK";
		} else {
			ciphers = "ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-DSS-AES128-GCM-SHA256:kEDH+AESGCM:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA256:DHE-RSA-AES256-SHA256:DHE-DSS-AES256-SHA:DHE-RSA-AES256-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:AES:CAMELLIA:DES-CBC3-SHA:!aNULL:!eNULL:!EXPORT:!DES:!RC4:!MD5:!PSK:!aECDH:!EDH-DSS-DES-CBC3-SHA:!EDH-RSA-DES-CBC3-SHA:!KRB5-DES-CBC3-SHA";
		}

		if (SSL_CTX_set_cipher_list(ctx->native_handle() , ciphers.c_str()) != 1) {
			std::cout << "Error setting cipher list" << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return ctx;
}

std::string NFCWS::GetPassword(){
	return "simple";
}