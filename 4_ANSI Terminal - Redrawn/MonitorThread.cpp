/*
 *	File:			MonitorThread.cpp
 *
 *	Contains:		implementation of worker thread
 *
 *	Project:		
 *
 *	Copyright:		(c) 1996 by Kwon, Jae-Rock. All right Reserved.
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

UINT MonitorThreadProc(LPVOID pParam)
{
	CCommPort* pCommPortInfo = (CCommPort*)pParam;
	DWORD dwTransfer, dwEvtMask;
	OVERLAPPED os;

	memset(&os, 0, sizeof(OVERLAPPED));
	os.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	ASSERT(os.hEvent);

	if(!SetCommMask(pCommPortInfo->GetPortHandle(), COMM_MASK)) 
		return FALSE;

	// if port is close, this thread is terminated by exiting the proc
	while(pCommPortInfo->GetOpenFlag()) 
	{
		dwEvtMask = 0;
		if(!WaitCommEvent(pCommPortInfo->GetPortHandle(), &dwEvtMask, &os)) {
			if(GetLastError() == ERROR_IO_PENDING) {
				GetOverlappedResult(pCommPortInfo->GetPortHandle(), &os, &dwTransfer, TRUE);
				os.Offset += dwTransfer;
			}
		}
		if((dwEvtMask & COMM_MASK) == COMM_MASK) {
            TRACE("Masked Event Occurred\n");
            ResetEvent(pCommPortInfo->GetPostEvent());
            ((CWnd*)(pCommPortInfo->GetNotifyWindow()))->PostMessage(WM_COMMNOTIFY32, 
                          (WPARAM)pCommPortInfo->GetPortHandle(), (LPARAM)CN_EVENT32);
            // wait for comm event notificaton complete
            WaitForSingleObject(pCommPortInfo->GetPostEvent(), INFINITE);
		} // if
	} // while
	
	CloseHandle(os.hEvent);
	SetEvent(pCommPortInfo->GetMonitorThreadKilledEvent());

	return TRUE;
}
