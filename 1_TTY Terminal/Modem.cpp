/*
 *	File:			Modem.cpp
 *
 *	Contains:		
 *
 *	Project:		Terminal Emulator for Win95
 *
 *	Copyright:		(c) 1997 Kwon, Jae-Rock. All right Reserved.
 *
 *	Written by:		Kwon, Jae-Rock
 *
 *	Change History(most recent first) :
 *
 *	<1> 97.03
 *
 */

#include "stdafx.h"
#include "Modem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CModem, CObject)

char *szConnectError[] = {
    "SUCCESS", "NO CARRIER", "ERROR", "NO DIALTONE", "BUSY", "NO ANSWER", NULL
}; // SUCCESS is dummy value

/////////////////////////////////////////////////////////////////////////////
// Modem Constructor/Destructor
	
CModem::CModem()
{
    SetConnectTimeout(60000L);
    SetResponseTimeout(2000L);
	SetInitCommand("ATZ");
}

CModem::~CModem()
{
    if(GetCommPort()->IsOpen())
        Close();
}

/////////////////////////////////////////////////////////////////////////////
// CModem Operation

BOOL CModem::Open(DIAL_MODE dialMode)
{
    GetCommPort()->ReadProfile();
	if(GetCommPort()->Open())
    {
        SetDialMode(dialMode);
	    Initialize();
        return TRUE;
    }
    else
    {
        GetCommPort()->DispError();
        return FALSE;
    }
}

void CModem::Close()
{
	GetCommPort()->Close();
}

/////////////////////////////////////////////////////////////////////////////
// CModem implementation
MODEM_CONNECT_ERROR CModem::ReadConnectError(char* lpszBuf)
{
    for(int i=0; szConnectError[i]; i++)
    {
        if(strstr(lpszBuf, szConnectError[i]))
            return (MODEM_CONNECT_ERROR)i; // connection error
    }
    return CE_SUCCESS;
}

void CModem::ReadLine(char* lpszBuf, int nBufSize)
{
    char cChar;

    while(TRUE)
    {
        if(GetCommPort()->Read(&cChar, 1) != 1)
            break;
        *lpszBuf++ = (cChar);
        if(--nBufSize <= 1)
            break;
        if(cChar == ASCII_LF)
            break;
    }
    *lpszBuf = NULL;
}

BOOL CModem::SendCommand(CString strCommand)
{
    GetCommPort()->Write(strCommand);
    GetCommPort()->Write("\r");

    return WaitForResponse();
}

MODEM_ERROR CModem::Initialize()
{
	SendCommand(GetInitCommand());
    return WaitForResponse();
}

MODEM_ERROR CModem::Dial(CString strNo)
{
	GetCommPort()->Write("ATD");
    GetCommPort()->Write((GetDialMode() == TONE_DIAL) ? "T" : "P");
   	GetCommPort()->Write(strNo);
	GetCommPort()->Write("\r");

	return WaitForConnection();
}

MODEM_ERROR CModem::HangUp()
{
	DWORD dwTimeout;
    
    GetCommPort()->DTR(FALSE);
    dwTimeout = GetTickCount()+1000L;
    while(GetTickCount() < dwTimeout)
        ;
	GetCommPort()->DTR(TRUE);

    GetCommPort()->Write("+++");
    WaitForResponse();
   	GetCommPort()->Write("ATH0\r");
    if(WaitForResponse() == MODEM_SUCCESS)
        return MODEM_SUCCESS;
    
	return MODEM_DISCONNECT_FAILED;
}

MODEM_ERROR CModem::Answer()
{
	GetCommPort()->Write("ATA");

	return WaitForConnection();
}

MODEM_ERROR CModem::WaitForConnection()
{
    DWORD dwTimeout;
    MODEM_CONNECT_ERROR connectError;
    char szBuf[MAXBUF];

    dwTimeout = GetTickCount() + GetConnectTimeout(); 
    while(GetTickCount() < dwTimeout)
    {
        ReadLine(szBuf, MAXBUF);
        connectError = ReadConnectError(szBuf);
        if(connectError != CE_SUCCESS)
            return MODEM_NO_CONNECTION;
        if(strstr(szBuf, "CONNECT"))
            return MODEM_SUCCESS;
    }
    return MODEM_NO_CONNECTION;
}

MODEM_ERROR CModem::WaitForResponse()
{
    DWORD dwTimeout;
    char szBuf[MAXBUF];

    dwTimeout = GetTickCount() + GetResponseTimeout(); 
    while(GetTickCount() < dwTimeout)
    {
        ReadLine(szBuf, MAXBUF);
        if(!strncmp(szBuf, "OK", 2))
            return MODEM_SUCCESS;
    }
    return MODEM_NO_RESPONSE;
}
/////////////////////////////////////////////////////////////////////////////
// CModem diagnostics

#ifdef _DEBUG
void CModem::AssertValid() const
{
	CObject::AssertValid();
}

void CModem::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
