/*
 *	File:			MonitorThread.h
 *
 *	Contains:		Interface of the controlling function of the monitor worker thread
 *
 *	Project:		Communication module for Intellegent User Interface.
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

// Controlling function for the worker thread
UINT MonitorThreadProc(LPVOID pParam /* CCommPort ptr */);
