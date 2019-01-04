/*
 *	File:			CommPort.h
 *
 *	Contains:		
 *
 *	Project:		
 *
 *	Copyright:		(c) 1997 by Kwon, Jae-Rock. All right Reserved.
 *
 *	Written by:		Kwon, Jae-Rock
 *
 *	Change History(most recent first) :
 *
 *	<1> 97.03
 *
 */

#ifndef _COMMPORT_H_
#define _COMMPORT_H_

//
#define MAXBUF              80

// define REGISTRY KEY
#define COMM_REGISTRY_KEY   "Chungnyun Soft"
#define COMM_PORT_SECTION   "CommPort Settings"

// define communication event message
#define WM_COMMNOTIFY32     WM_USER+1
#define CN_EVENT32          0x04

// define ASCII
#define ASCII_DLE		0x10
#define ASCII_ETX		0x03
#define ASCII_CAN		0x18
#define ASCII_EOT		0x04

#define ASCII_BEL       0x07
#define ASCII_BS        0x08
#define ASCII_TAB       0x09
#define ASCII_LF		0x0A
#define ASCII_CR		0x0D
#define ASCII_XON		0x11
#define ASCII_XOFF		0x13
#define ASCII_ESC       0x1B

/////////////////////////////////////////////////////////////////////////////
// RX QUEUE SIZE
#define RXQUEUESIZE	    4096	// Receive Queue Size
#define TXQUEUESIZE	    4096	// Transmit Queue Size

#define COMM_MASK	    EV_RXCHAR

/////////////////////////////////////////////////////////////////////////////
// Flow control flags
#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
#define FC_XONXOFF      0x04

/////////////////////////////////////////////////////////////////////////////
#define MAXCOMMPORTS	8

typedef enum { 
    COM1, COM2, COM3, COM4, COM5, COM6, COM7, COM8 
} COMM_PORT ;

typedef enum {
    PORT_NO_ERROR, PORT_OPEN_ERROR, PORT_HANSHAKE_LINE_IN_USE
} COMM_ERROR;

extern char *pstrCommPortName[];

/////////////////////////////////////////////////////////////////////////////
// Communication Port class ver 0.1

extern DWORD dwBaudRateTable[];
extern BYTE bParityTable[];
extern BYTE bStopBitsTable[];
extern BYTE bDataBitsTable[];
extern COMM_PORT portTable[];

class CPortSetting 
{
// Attributes
protected:
    DWORD       m_dwBaudRate;
	BYTE	    m_bDataBits;
	BYTE	    m_bParity;
	COMM_PORT   m_port;
	BOOL	    m_fRTSCTS;
	BYTE		m_bStopBits;
	BOOL    	m_fXONXOFF;
	BOOL	    m_fDTRDSR;

// Operations
public:
    DWORD       GetBaudRate() { return m_dwBaudRate; }
    void        SetBaudRate(DWORD dwBaudRate) { m_dwBaudRate = dwBaudRate; }
    BYTE        GetDataBits() { return m_bDataBits; }
    void        SetDataBits(BYTE bDataBits) { m_bDataBits = bDataBits; }
    BYTE        GetParity() { return m_bParity; }
    void        SetParity(BYTE bParity) { m_bParity = bParity; }
	COMM_PORT   GetPort() { return m_port; }
    void        SetPort(COMM_PORT port) { m_port = port; }
    BOOL        GetRTSCTS() { return m_fRTSCTS; }
    void        SetRTSCTS(BOOL fRTSCTS) { m_fRTSCTS = fRTSCTS; }
    BYTE        GetStopBits() { return m_bStopBits; }
    void        SetStopBits(BYTE bStopBits) { m_bStopBits = bStopBits; }
    BOOL        GetXONXOFF() { return m_fXONXOFF; }
    void        SetXONXOFF(BOOL fXONXOFF) { m_fXONXOFF = fXONXOFF; }
    BOOL        GetDTRDSR() { return m_fDTRDSR; }
    void        SetDTRDSR(BOOL fDTRDSR) { m_fDTRDSR = fDTRDSR; }
    
// Implementation
public:
    int         GetBaudRateIndex(DWORD dwBaudRate);
    int         GetParityIndex(BYTE bParity);
    int         GetStopBitsIndex(BYTE bStopBits);
    int         GetDataBitsIndex(BYTE bDataBits);
};

class CCommPort : public CObject
{
//protected: // create from serialization only
public:
	CCommPort();
	DECLARE_DYNCREATE(CCommPort)

// Attributes
protected:
	HANDLE		m_hCommPort;
	COMM_PORT	m_portID;
	BOOL		m_fOpen;
	DCB			m_dcb;
	OVERLAPPED	m_osWrite, m_osRead;
	CWinThread*	m_pMonitorThread;
    HANDLE      m_hPostEvent;   // comm event notification event
	HANDLE		m_hEventMonitorThreadKilled;
//	LINE_STATUS	m_lineStatus;				// current line status
//	COMM_MSG	m_commMsg;					// result code from modem
	HWND		m_hNotifyWnd;				// COMM_MSG notify window
    CPortSetting m_portSetting;
    COMM_ERROR  m_error;

// Operations
public:
	char*		GetPortName(COMM_PORT portName) { return pstrCommPortName[portName]; }

    COMM_PORT	GetPortID() { return m_portID; }
	void		SetPortID(COMM_PORT portID) { m_portID = portID; }
	BOOL		GetOpenFlag() { return m_fOpen; }
	void		SetOpenFlag(BOOL fPortOpen) { m_fOpen = fPortOpen; }
	HANDLE		GetPortHandle() { return m_hCommPort; }
	void		SetPortHandle(HANDLE hCommPort) { m_hCommPort = hCommPort; }
	HANDLE		GetReadOSEvent() { return m_osRead.hEvent; }
	void		SetReadOSEvent(HANDLE hReadOSEvent) { m_osRead.hEvent = hReadOSEvent; }
	OVERLAPPED	GetReadOS() { return m_osRead; }
	HANDLE		GetWriteOSEvent() { return m_osWrite.hEvent; }
	void		SetWriteOSEvent(HANDLE hWriteOSEvent) { m_osWrite.hEvent = hWriteOSEvent; }
	OVERLAPPED	GetWriteOS() { return m_osWrite; }

	CWinThread* GetMonitorThread() { return m_pMonitorThread; }
	void		SetMonitorThread(CWinThread* pMonitorThread) { m_pMonitorThread = pMonitorThread; }
	HANDLE		GetPostEvent() { return m_hPostEvent; }
	void		SetPostEvent(HANDLE hPostEvent) { m_hPostEvent = hPostEvent; }
	HANDLE		GetMonitorThreadKilledEvent() { return m_hEventMonitorThreadKilled; }
	void		SetMonitorThreadKilledEvent(HANDLE hEventMonitorThreadKilled) 
                    { m_hEventMonitorThreadKilled = hEventMonitorThreadKilled; }

	HWND		GetNotifyWindow() { return m_hNotifyWnd; }
	void		SetNotifyWindow(HWND hNotifyWnd) { m_hNotifyWnd = hNotifyWnd; }
    CPortSetting GetPortSetting() { return m_portSetting; }
    void        SetPortSetting(CPortSetting portSetting) { m_portSetting = portSetting; }
    COMM_ERROR  GetError() { return m_error; }
    void        SetError(COMM_ERROR error) { m_error = error; }

    // Comm port setting
    DWORD       GetBaudRate() { return m_portSetting.GetBaudRate(); }
    void        SetBaudRate(DWORD dwBaudRate) { m_portSetting.SetBaudRate(dwBaudRate); }
    BYTE        GetDataBits() { return m_portSetting.GetDataBits(); }
    void        SetDataBits(BYTE bDataBits) { m_portSetting.SetDataBits(bDataBits); }
    BYTE        GetParity() { return m_portSetting.GetParity(); }
    void        SetParity(BYTE bParity) { m_portSetting.SetParity(bParity); }
	COMM_PORT   GetPort() { return m_portSetting.GetPort(); }
    void        SetPort(COMM_PORT port) { m_portSetting.SetPort(port); SetPortID(port); }
    BOOL        GetRTSCTS() { return m_portSetting.GetRTSCTS(); }
    void        SetRTSCTS(BOOL fRTSCTS) { m_portSetting.SetRTSCTS(fRTSCTS); }
    BYTE        GetStopBits() { return m_portSetting.GetStopBits(); }
    void        SetStopBits(BYTE bStopBits) { m_portSetting.SetStopBits(bStopBits); }
    BOOL        GetXONXOFF() { return m_portSetting.GetXONXOFF(); }
    void        SetXONXOFF(BOOL fXONXOFF) { m_portSetting.SetXONXOFF(fXONXOFF); }
    BOOL        GetDTRDSR() { return m_portSetting.GetDTRDSR(); }
    void        SetDTRDSR(BOOL fDTRDSR) { m_portSetting.SetDTRDSR(fDTRDSR); }

    int         GetBaudRateIndex(DWORD dwBaudRate) { return m_portSetting.GetBaudRateIndex(dwBaudRate); }
    int         GetParityIndex(BYTE bParity) { return m_portSetting.GetParityIndex(bParity); }
    int         GetStopBitsIndex(BYTE bStopBits) { return m_portSetting.GetStopBitsIndex(bStopBits); }
    int         GetDataBitsIndex(BYTE bDataBits) { return m_portSetting.GetDataBitsIndex(bDataBits); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommPort)
	//}}AFX_VIRTUAL

// Implementation
public:
	void		StartMonitorThread();
	DWORD		Read(LPTSTR lpszBlock, int nMaxLength);
	DWORD		Write(BYTE bByte);
	DWORD		Write(LPCTSTR lpszBlock, int nMaxLength);
    DWORD       Write(LPCTSTR lpszBlock);
	void		Clear();
	BOOL		Open();
	void		Close();
	void		EnableMonitorThread();
	void		DisableMonitorThread();
	BOOL		SetDCB(DWORD BaudRate = CBR_14400,		// current baud rate 
					BYTE ByteSize = 8,					// number of bits/byte, 4-8 
					BYTE Parity = NOPARITY,				// 0-4=no,odd,even,mark,space 
					BYTE StopBits = 0,					// 0,1,2 = 1, 1.5, 2 
					int nFlag = FC_RTSCTS);// Flow control flag
    BOOL        IsOpen();
    void        DispError();
    void        ReadProfile();
    void        WriteProfile();
    COMM_ERROR  DTR(BOOL fSetting);

	virtual ~CCommPort();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

#endif
/////////////////////////////////////////////////////////////////////////////

