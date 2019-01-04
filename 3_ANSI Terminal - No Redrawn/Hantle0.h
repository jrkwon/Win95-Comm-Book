// Hantle0.h : main header file for the HANTLE0 application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHantle0App:
// See Hantle0.cpp for the implementation of this class
//

class CHantle0App : public CWinApp
{
public:
	CHantle0App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHantle0App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHantle0App)
	afx_msg void OnAppAbout();
	afx_msg void OnUpdatePhoneConnect(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
