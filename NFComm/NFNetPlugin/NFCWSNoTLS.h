// -------------------------------------------------------------------------
//    @FileName			:		NFCWSNoTLS.h
//    @Author			:		Stone.xin
//    @Date				:		2016-12-22
//    @Module			:		NFCWSNoTLS
// -------------------------------------------------------------------------

#ifndef NFC_WS_H
#define NFC_WS_H

#include "NFIWS.h"

#pragma pack(push, 1)

class NFCWSNoTLS : public NFIWS
{
public:
    template<typename BaseType>
	NFCWSNoTLS(BaseType* pBaseType, void (BaseType::*handleRecieve)(websocketpp::connection_hdl, const std::string&, WSObjectPtr), void (BaseType::*handleEvent)(websocketpp::connection_hdl, NF_WS_EVENT, WSObjectPtr))
    {
        mRecvCB = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        mEventCB = std::bind(handleEvent, pBaseType, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        //mstrIP = "";
        mnPort = 0;
        mnCpuCount = 0;
        //mbServer = true;
        mbWorking = false;
        
        mnSendMsgTotal = 0;
        mnReceiveMsgTotal = 0;
    }
    virtual ~NFCWSNoTLS() {};

public:
    virtual bool Execute();

    virtual int Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount = 4);

    virtual bool Final();

	virtual bool SendMsgToAllClient(const char* msg, const uint32_t nLen);
	virtual bool SendMsgToClient(const char* msg, const uint32_t nLen, const std::vector<websocketpp::connection_hdl>&);
	virtual bool SendMsgToClient(const char* msg, const uint32_t nLen, websocketpp::connection_hdl);

    virtual bool AddNetObject(websocketpp::connection_hdl conn,WSObjectPtr pObject);
    virtual WSObjectPtr GetNetObject(websocketpp::connection_hdl conn);

	void CloseObject(websocketpp::connection_hdl hd, int nCloseCode=1000, const std::string& strCloseReason="");
private:
	typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> context_ptr;

	void ExecuteClose();
	bool CloseSocketAll();

	void OnMessageHandler(websocketpp::connection_hdl hd, NFWebSockConf::message_ptr msg);
	void OnOpenHandler(websocketpp::connection_hdl hd);
	bool RemoveConnection(websocketpp::connection_hdl hd, NF_WS_EVENT evt, int nCloseCode = 1000, const std::string& strCloseReason = "");
	void OnCloseHandler(websocketpp::connection_hdl hd);
	void OnFailHandler(websocketpp::connection_hdl hd);
	void OnInterruptHandler(websocketpp::connection_hdl hd);
	bool OnPongHandler(websocketpp::connection_hdl hd, std::string str);
	void OnPongTimeOutHandler(websocketpp::connection_hdl hd, std::string str);
	void OnHttp(websocketpp::connection_hdl hdl);

private:
    //<fd,object>
	typedef std::map<websocketpp::connection_hdl, WSObjectPtr, std::owner_less<websocketpp::connection_hdl> > session_list;
	session_list mmObject;
    std::vector<websocketpp::connection_hdl> mvRemoveObject;

    int mnMaxConnect;
    int mnPort;
    int mnCpuCount;

    bool mbWorking;

    int64_t mnSendMsgTotal;
    int64_t mnReceiveMsgTotal;

	NFWebSockConfNoTLS	m_EndPoint;
    //////////////////////////////////////////////////////////////////////////

	NF_WS_MSG_CALL_BACK mRecvCB;
	NF_WS_EVENT_CALL_BACK mEventCB;

    //////////////////////////////////////////////////////////////////////////
};

#pragma pack(pop)

#endif
