/*
 *	File:			CommPort.cpp
 *
 *	Contains:		
 *
 *	Project:		
 *
 *	Copyright:		(c) 1996 by the LG Electonics. All right Reserved.
 *
 *	Written by:		Kwon, Jae-Rock
 *
 *	Change History(most recent first) :
 *
 *	<1> 96.06
 *
 */

#include "stdafx.h"
#include "CommPort.h"
#include "MonitorThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CCommPort, CObject)

#define MAX_BAUDRATE_TBL    15
#define MAX_PARITY_TBL      5
#define MAX_STOPBITS_TBL    3
#define MAX_DATABITS_TBL    5

/////////////////////////////////////////////////////////////////////////////
// 
char *pstrCommPortName[] = { 
    "COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8" 
};

DWORD dwBaudRateTable[] = {
    CBR_110, CBR_300, CBR_600, CBR_1200, CBR_2400, CBR_4800, CBR_9600, CBR_14400, 
    CBR_19200, CBR_38400, CBR_56000, CBR_57600, CBR_115200, CBR_128000, CBR_256000
};

BYTE bParityTable[] = {
    NOPARITY, ODDPARITY, EVENPARITY, MARKPARITY, SPACEPARITY
};

BYTE bStopBitsTable[] = {
    ONESTOPBIT, ONE5STOPBITS, TWOSTOPBITS
};

BYTE bDataBitsTable[] = {
    4, 5, 6, 7, 8
};

COMM_PORT portTable[] = {
    COM1, COM2, COM3, COM4, COM5, COM6, COM7, COM8
};

CString strError[] = {
    "", "Can not open the serial communication port"
};

enum { 
    ITEM_BAUDRATE, 
    ITEM_DATABITS, 
    ITEM_PARITY, 
    ITEM_PORT, 
    ITEM_RTSCTS, 
    ITEM_STOPBITS, 
    ITEM_XONXOFF, 
    ITEM_DTRDSR 
};

CString strPortItem[] = {
    "BaudRate",
	"DataBits",
	"Parity",
	"Port",
	"RTSCTS",
	"StopBits",
	"XONXOFF",
	"DTRDSR"
};

/////////////////////////////////////////////////////////////////////////////
// default setting for comm port
#define DEFAULT_BAUDRATE    CBR_38400
#define DEFAULT_DATABITS    8
#define DEFAULT_PARITY      NOPARITY
#define DEFAULT_PORT        COM1
#define DEFAULT_RTSCTS      TRUE
#define DEFAULT_STOPBITS    ONESTOPBIT
#define DEFAULT_XONXOFF     TRUE
#define DEFAULT_DTRDSR      TRUE

/////////////////////////////////////////////////////////////////////////////
// Table convertor 
int CPortSetting::GetBaudRateIndex(DWORD dwBaudRate)
{
    for(int i=0; i < MAX_BAUDRATE_TBL; i++)
        if(dwBaudRate == dwBaudRateTable[i])
            return i;
    return -1;
}

int CPortSetting::GetParityIndex(BYTE bParity)
{
    for(int i=0; i < MAX_PARITY_TBL; i++)
        if(bParity == bParityTable[i])
            return i;
    return -1;
}

int CPortSetting::GetStopBitsIndex(BYTE bStopBits)
{
    for(int i=0; i < MAX_STOPBITS_TBL; i++)
        if(bStopBits == bStopBitsTable[i])
            return i;
    return -1;
}

int CPortSetting::GetDataBitsIndex(BYTE bDataBits)
{
    for(int i=0; i < MAX_DATABITS_TBL; i++)
        if(bDataBits == bDataBitsTable[i])
            return i;
    return -1;
}

/////////////////////////////////////////////////////////////////////////////
// CCommPort Constructor/Destructor
	
CCommPort::CCommPort()
{
	// prevent for getting comm port handle before port open
	SetOpenFlag(FALSE);

	// default setting for comm port
    m_portSetting.SetBaudRate(DEFAULT_BAUDRATE); 
	m_portSetting.SetDataBits(DEFAULT_DATABITS);
	m_portSetting.SetParity(DEFAULT_PARITY);
	m_portSetting.SetPort(DEFAULT_PORT);
	m_portSetting.SetRTSCTS(DEFAULT_RTSCTS);
	m_portSetting.SetStopBits(DEFAULT_STOPBITS);
	m_portSetting.SetXONXOFF(DEFAULT_XONXOFF);
	m_portSetting.SetDTRDSR(DEFAULT_DTRDSR);
}

CCommPort::~CCommPort()
{
}

/////////////////////////////////////////////////////////////////////////////
// Operation


/////////////////////////////////////////////////////////////////////////////
// CCommPort implementation

void CCommPort::StartMonitorThread()
{
	if(GetMonitorThread() == NULL)
	{ // if comm port don't have monitor thread
		CWinThread* pMonitorThread = 
			AfxBeginThread(MonitorThreadProc, this, 
				THREAD_PRIORITY_BELOW_NORMAL);
		SetMonitorThread(pMonitorThread);
	}


	TRACE("Monitor Thread started.\n");
}

/////////////////////////////////////////////////////////////////////////////
// if return 0, some error occur.
DWORD CCommPort::Read(LPTSTR lpszBlock, int nMaxLength)
{
	// Read comm port by overlapped I/O
	BOOL fReadStat;
	COMSTAT ComStat;
	DWORD dwErrorFlags, dwError, dwLength;

	ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
	if(dwErrorFlags > 0) {
		TRACE("Comm port read error\n");
		return (DWORD)0;
	}
	dwLength = min((DWORD)nMaxLength, ComStat.cbInQue);
	if(dwLength > 0) {
		fReadStat = ReadFile(GetPortHandle(), lpszBlock, dwLength, &dwLength, &GetReadOS());
		if(!fReadStat) {
			if(GetLastError() == ERROR_IO_PENDING) {

				TRACE("IO Pending...\n");

				while(!GetOverlappedResult(GetPortHandle(), &GetReadOS(), &dwLength, TRUE))
				{
					dwError = GetLastError();
					if(dwError == ERROR_IO_INCOMPLETE)
					{ // normal result if not finished
						continue;
					}
					else
					{
						// an error occurred, try to recover
						TRACE("<CE-%u>\n", dwError);

						ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
						if(dwErrorFlags > 0)
						{
							TRACE("<CE-%u>\n", dwErrorFlags);
						}
						break;
					}
				}
			}
			else
			{ // some other error occured
				dwLength = 0;
				ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
				if(dwErrorFlags > 0)
				{
					TRACE("<CE-%u>\n", dwErrorFlags);
				}
			}
		}
	}

//	TRACE("%s (%d) read\n", lpszBlock, dwLength);
	return dwLength;
}

DWORD CCommPort::Write(BYTE bByte)
{
	BOOL fWriteStat;
	COMSTAT ComStat;
	DWORD dwBytesWritten, dwError, dwErrorFlags;

	fWriteStat = WriteFile(GetPortHandle(), (LPTSTR)&bByte, 1, &dwBytesWritten, &GetWriteOS());

	if(!fWriteStat)
	{
		if(GetLastError() == ERROR_IO_PENDING) 
		{

			while(!GetOverlappedResult(GetPortHandle(), &GetWriteOS(), &dwBytesWritten, TRUE))
			{
				dwError = GetLastError();
				if(dwError == ERROR_IO_INCOMPLETE)
				{ // normal result if not finished
					continue;
				}
				else
				{
					// an error occurred, try to recover
					TRACE("<CE-%u>\n", dwError);

					ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
					if(dwErrorFlags > 0)
					{
						TRACE("<CE-%u>\n", dwErrorFlags);
					}
					break;
				}
			}
		}
		else
		{ // some other error occured
			dwBytesWritten = 0;
			ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
			if(dwErrorFlags > 0)
			{
				TRACE("<CE-%u>\n", dwErrorFlags);
			}
		}
	}
	return dwBytesWritten;
}

DWORD CCommPort::Write(LPCTSTR lpszBlock, int nMaxLength)
{
	BOOL fWriteStat;
	COMSTAT ComStat;
	DWORD dwBytesWritten, dwError, dwErrorFlags;

	fWriteStat = WriteFile(GetPortHandle(), lpszBlock, nMaxLength, &dwBytesWritten, &GetWriteOS());
	
	if(!fWriteStat)
	{
		if(GetLastError() == ERROR_IO_PENDING) 
		{

			while(!GetOverlappedResult(GetPortHandle(), &GetWriteOS(), &dwBytesWritten, TRUE))
			{
				dwError = GetLastError();
				if(dwError == ERROR_IO_INCOMPLETE)
				{ // normal result if not finished
					continue;
				}
				else
				{
					// an error occurred, try to recover
					TRACE("<CE-%u>\n", dwError);

					ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
					if(dwErrorFlags > 0)
					{
						TRACE("<CE-%u>\n", dwErrorFlags);
					}
					break;
				}
			}
		}
		else
		{ // some other error occured
			dwBytesWritten = 0;
			ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
			if(dwErrorFlags > 0)
			{
				TRACE("<CE-%u>\n", dwErrorFlags);
			}
		}
	}
	return dwBytesWritten;
}

DWORD CCommPort::Write(LPCTSTR lpszBlock)
{
	BOOL fWriteStat;
	COMSTAT ComStat;
	DWORD dwBytesWritten, dwError, dwErrorFlags;
    int nMaxLength = strlen(lpszBlock);

    fWriteStat = WriteFile(GetPortHandle(), lpszBlock, nMaxLength, &dwBytesWritten, &GetWriteOS());
	
	if(!fWriteStat)
	{
		if(GetLastError() == ERROR_IO_PENDING) 
		{

			while(!GetOverlappedResult(GetPortHandle(), &GetWriteOS(), &dwBytesWritten, TRUE))
			{
				dwError = GetLastError();
				if(dwError == ERROR_IO_INCOMPLETE)
				{ // normal result if not finished
					continue;
				}
				else
				{
					// an error occurred, try to recover
					TRACE("<CE-%u>\n", dwError);

					ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
					if(dwErrorFlags > 0)
					{
						TRACE("<CE-%u>\n", dwErrorFlags);
					}
					break;
				}
			}
		}
		else
		{ // some other error occured
			dwBytesWritten = 0;
			ClearCommError(GetPortHandle(), &dwErrorFlags, &ComStat);
			if(dwErrorFlags > 0)
			{
				TRACE("<CE-%u>\n", dwErrorFlags);
			}
		}
	}
	return dwBytesWritten;
}

void CCommPort::Clear()
{
	PurgeComm(GetPortHandle(), PURGE_TXABORT | PURGE_RXABORT 
						| PURGE_TXCLEAR | PURGE_RXCLEAR);
}

BOOL CCommPort::SetDCB(DWORD dwBaudRate,			// current baud rate 
						BYTE bByteSize,				// number of bits/byte, 4-8 
						BYTE bParity,				// 0-4=no,odd,even,mark,space 
						BYTE bStopBits,				// 0,1,2 = 1, 1.5, 2 
						int nFlag)	                // Flow control flag
{
	m_dcb.DCBlength = sizeof(DCB);
	GetCommState(GetPortHandle(), &m_dcb);

	m_dcb.BaudRate = dwBaudRate;
	m_dcb.ByteSize = bByteSize;
	m_dcb.Parity = bParity;
	m_dcb.StopBits = bStopBits;

	// set hardware control
	BYTE bSet = (BYTE)((nFlag & FC_DTRDSR) != 0);
	m_dcb.fOutxDsrFlow = bSet;
	m_dcb.fDtrControl = (bSet) ? DTR_CONTROL_HANDSHAKE : DTR_CONTROL_ENABLE;
	
	bSet = (BYTE)((nFlag & FC_RTSCTS) != 0);
	m_dcb.fOutxCtsFlow = bSet;
	m_dcb.fRtsControl = (bSet) ? RTS_CONTROL_HANDSHAKE : RTS_CONTROL_ENABLE;

	m_dcb.fInX = m_dcb.fOutX = bSet;
	m_dcb.XonChar = ASCII_XON;
	m_dcb.XoffChar = ASCII_XOFF;
	m_dcb.XonLim = 100;
	m_dcb.XoffLim = 100;

	m_dcb.fBinary = TRUE;
	m_dcb.fParity = TRUE;

	TRACE("Setup DCB\n");

	return SetCommState(GetPortHandle(), &m_dcb);
}

BOOL CCommPort::Open()
{
	if(GetOpenFlag())
		return FALSE;

    ///////////////////////////////////
    //  Read port setting value
    COMM_PORT portID    = GetPortSetting().GetPort();
	DWORD dwBaudRate    = GetPortSetting().GetBaudRate();
	BYTE bByteSize      = GetPortSetting().GetDataBits();   // number of bits/byte, 4-8 
	BYTE bParity        = GetPortSetting().GetParity();	    // 0-4=no,odd,even,mark,space 
	BYTE bStopBits      = GetPortSetting().GetStopBits();   // 0,1,2 = 1, 1.5, 2 

    int nFlag;
    nFlag = GetPortSetting().GetRTSCTS() ? FC_RTSCTS : 0;  
    nFlag |= GetPortSetting().GetDTRDSR() ? FC_DTRDSR : 0; 
    nFlag |= GetPortSetting().GetXONXOFF() ? FC_XONXOFF : 0;

    ///////////////////////////////////
	//	Open Comm Port
	HANDLE hCommPort = CreateFile(GetPortName(portID),
						GENERIC_READ | GENERIC_WRITE,
						0,	// Exclusive access
						NULL, // no security attrs
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
						NULL);
	if(hCommPort == (HANDLE)-1)
    {
        SetError(PORT_OPEN_ERROR);
		return FALSE;
    }

	SetPortHandle(hCommPort);
	SetOpenFlag(TRUE);
	
	//////////////////////////////////////////
    // SetCommMask(GetPortHandle(), COMM_MASK);
	SetupComm(GetPortHandle(), RXQUEUESIZE, TXQUEUESIZE);

	//////////////////////////////////////////
	// set up for overlapped non-blocking I/O
	COMMTIMEOUTS CommTimeOuts;
    CommTimeOuts.ReadIntervalTimeout = MAXDWORD;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0; 
    CommTimeOuts.ReadTotalTimeoutConstant = 0; 
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0; 
    CommTimeOuts.WriteTotalTimeoutConstant = 5000; 
	SetCommTimeouts(GetPortHandle(), &CommTimeOuts);

	//////////////////////////////////////////////
	// set up connection
	if(SetDCB(dwBaudRate, bByteSize, bParity, bStopBits, nFlag)) {
		SetMonitorThread(NULL);		// Monitor thread initialize
		StartMonitorThread();		// Monitor Thread Start
		// assert DTR
		DTR(TRUE);
	}
	else {
		SetOpenFlag(FALSE);
		CloseHandle(GetPortHandle());
		return FALSE;
	}

	///////////////////////////////////////////
	// Create Events
	HANDLE hPostEvent = CreateEvent(NULL,	// no security
										TRUE,	// manual reset
										TRUE,	// intial event is set
										NULL);	// no name 
	HANDLE hEventMonitorThreadKilled = CreateEvent(NULL,
										TRUE,	// manual reset
										FALSE,	// intial event is reset
										NULL);	// no name 
	SetPostEvent(hPostEvent);
	SetMonitorThreadKilledEvent(hEventMonitorThreadKilled);

	HANDLE hReadOSEvent = CreateEvent(NULL,	// no security
									TRUE,	// manual reset
									FALSE,	// initial event is reset
									NULL);	// no name
	HANDLE hWriteOSEvent = CreateEvent(NULL,// no security
									TRUE,	// manual reset
									FALSE,	// initial event is reset
									NULL);	// no name
	SetReadOSEvent(hReadOSEvent);
	SetWriteOSEvent(hWriteOSEvent);
	GetReadOS().Offset = GetWriteOS().Offset = 0;
	
	// Clear comm buffer	
	PurgeComm(GetPortHandle(), PURGE_TXABORT | PURGE_RXABORT 
						| PURGE_TXCLEAR | PURGE_RXCLEAR);

	TRACE("Open Comm Port\n");

	return TRUE;
}

void CCommPort::Close()
{
	if(GetOpenFlag() == FALSE)
		return;

	SetOpenFlag(FALSE); // monitor thread killed by exiting the proc
	SetCommMask(GetPortHandle(), 0);

	DWORD dwExitCode;
	
	if(GetExitCodeThread(GetMonitorThread()->m_hThread, &dwExitCode) && 
		dwExitCode == STILL_ACTIVE)
	{	// Wait for monitor thread killed
		WaitForSingleObject(GetMonitorThreadKilledEvent(), INFINITE);
	}
	SetMonitorThread(NULL);
	
	// drop DTR
	DTR(FALSE);
	// flush buffer
	PurgeComm(GetPortHandle(), PURGE_TXABORT | PURGE_RXABORT 
						| PURGE_TXCLEAR | PURGE_RXCLEAR);


	CloseHandle(GetPortHandle());

	CloseHandle(GetPostEvent());
	CloseHandle(GetMonitorThreadKilledEvent());

	CloseHandle(GetReadOSEvent());
	CloseHandle(GetWriteOSEvent());
	TRACE("Close Comm Port\n");
}

BOOL CCommPort::IsOpen()
{
    return GetOpenFlag();
}

void CCommPort::EnableMonitorThread()
{
	SetCommMask(GetPortHandle(), COMM_MASK);
}

void CCommPort::DisableMonitorThread()
{
	SetCommMask(GetPortHandle(), 0);
}

COMM_ERROR CCommPort::DTR(BOOL fSetting)
{
	if(m_dcb.fDtrControl == DTR_CONTROL_HANDSHAKE)
        return PORT_HANSHAKE_LINE_IN_USE;
    EscapeCommFunction(GetPortHandle(), (fSetting) ? SETDTR : CLRDTR);
    return PORT_NO_ERROR;
}

void CCommPort::DispError()
{
    COMM_ERROR error;

    error = GetError();
    if(error == PORT_NO_ERROR)
        return;
    AfxMessageBox(strError[error]);
}

void CCommPort::ReadProfile()
{
    int  nBaudRate, nDataBits, nParity, nPort, nStopBits;
    BOOL fRTSCTS, fXONXOFF, fDTRDSR;

    CWinApp* pApp = AfxGetApp();

	nBaudRate = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_BAUDRATE], 
                                      GetPortSetting().GetBaudRateIndex(DEFAULT_BAUDRATE));
	nDataBits = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_DATABITS], 
                                      GetPortSetting().GetDataBitsIndex(DEFAULT_DATABITS));
	nParity   = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_PARITY], 
                                      GetPortSetting().GetParityIndex(DEFAULT_PARITY));
	nPort     = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_PORT], DEFAULT_PORT);
	fRTSCTS   = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_RTSCTS], DEFAULT_RTSCTS);
	nStopBits = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_STOPBITS], 
                                      GetPortSetting().GetStopBitsIndex(DEFAULT_STOPBITS));
	fXONXOFF  = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_XONXOFF], DEFAULT_XONXOFF);
	fDTRDSR   = pApp->GetProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_DTRDSR], DEFAULT_DTRDSR);

    SetBaudRate(dwBaudRateTable[nBaudRate]);
	SetDataBits(bDataBitsTable[nDataBits]);
	SetParity(bParityTable[nParity]);
	SetPort(portTable[nPort]);
	SetRTSCTS(fRTSCTS);
	SetStopBits(bStopBitsTable[nStopBits]);
	SetXONXOFF(fXONXOFF);
	SetDTRDSR(fDTRDSR);
}

void CCommPort::WriteProfile()
{
    int  nBaudRate, nDataBits, nParity, nPort, nStopBits;
    BOOL fRTSCTS, fXONXOFF, fDTRDSR;
    CWinApp* pApp = AfxGetApp();
    
    nBaudRate = GetBaudRateIndex(GetBaudRate());
    nDataBits = GetDataBitsIndex(GetDataBits());
    nParity   = GetParityIndex(GetParity());
    nPort     = GetPort();
    nStopBits = GetStopBitsIndex(GetStopBits());
    fRTSCTS   = GetRTSCTS();
    fXONXOFF  = GetXONXOFF();
    fDTRDSR   = GetDTRDSR();

	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_BAUDRATE], nBaudRate);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_DATABITS], nDataBits);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_PARITY], nParity);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_PORT], nPort);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_RTSCTS], fRTSCTS);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_STOPBITS], nStopBits);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_XONXOFF], fXONXOFF);
	pApp->WriteProfileInt(COMM_PORT_SECTION, strPortItem[ITEM_DTRDSR], fDTRDSR);
}

/////////////////////////////////////////////////////////////////////////////
// CCommPort diagnostics

#ifdef _DEBUG
void CCommPort::AssertValid() const
{
	CObject::AssertValid();
}

void CCommPort::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
