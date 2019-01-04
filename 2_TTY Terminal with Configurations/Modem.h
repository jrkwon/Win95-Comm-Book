/*
 *	File:			Modem.h
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
#ifndef _MODEM_H_
#define _MODEM_H_

#include "CommPort.h"

typedef enum {
    MODEM_SUCCESS, MODEM_NO_RESPONSE, MODEM_NO_CONNECTION, MODEM_DISCONNECT_FAILED
} MODEM_ERROR;

typedef enum {
    CE_SUCCESS, CE_NO_CARRIER, CE_ERROR, CE_NO_DIALTONE, CE_BUSY, CE_NO_ANSWER
} MODEM_CONNECT_ERROR;

typedef enum {
    MODEM_INIT, MODEM_ANSWER, MODEM_DIAL, MODEM_HANGUP
} MODEM_COMMAND;

typedef enum {
    TONE_DIAL, PULSE_DIAL
} DIAL_MODE;

/////////////////////////////////////////////////////////////////////////////
// Modem command class ver 0.1

class CModem : public CObject
{
//protected: // create from serialization only
public:
	CModem();
	DECLARE_DYNCREATE(CModem)

// Attributes
protected:
	CCommPort	m_commPort;
	DIAL_MODE	m_dialMode;
    DWORD       m_dwConnectTimeout;
    DWORD       m_dwResponseTimeout;
	CString		m_strInitCommand;

// Operations
public:
	CCommPort*	GetCommPort() { return &m_commPort; }
	DIAL_MODE	GetDialMode() { return m_dialMode; }
	void		SetDialMode(DIAL_MODE dialMode) { m_dialMode = dialMode; }
    DWORD       GetConnectTimeout() { return m_dwConnectTimeout; }
    void        SetConnectTimeout(DWORD dwConnectTimeout) { m_dwConnectTimeout = dwConnectTimeout; }
    DWORD       GetResponseTimeout() { return m_dwResponseTimeout; }
    void        SetResponseTimeout(DWORD dwResponseTimeout) { m_dwResponseTimeout = dwResponseTimeout; }
    CString     GetInitCommand() { return m_strInitCommand; }
    void        SetInitCommand(CString strInitCommand) { m_strInitCommand = strInitCommand; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModem)
	//}}AFX_VIRTUAL

// Implementation
public:
    BOOL        Open(DIAL_MODE dialMode=TONE_DIAL);
	void		Close();
	MODEM_ERROR	Initialize();
	MODEM_ERROR	Dial(CString strNo);
	MODEM_ERROR	HangUp();
	MODEM_ERROR	Answer();
    BOOL        SendCommand(CString strCommand);
    MODEM_ERROR WaitForConnection();
    MODEM_ERROR WaitForResponse();
    void        ReadLine(char* lpszBuf, int nBufSize);
    MODEM_CONNECT_ERROR ReadConnectError(char* pszBuf);
		
	virtual ~CModem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

/////////////////////////////////////////////////////////////////////////////

#endif
