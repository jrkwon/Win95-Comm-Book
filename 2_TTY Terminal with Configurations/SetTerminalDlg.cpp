// SetTerminalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hantle0.h"
#include "SetTerminalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetTerminalDlg dialog


CSetTerminalDlg::CSetTerminalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetTerminalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetTerminalDlg)
	m_fAutoWrap = FALSE;
	m_fLocalEcho = FALSE;
	m_fReceiveLF = FALSE;
	m_fSendLF = FALSE;
	m_nTerminal = -1;
	//}}AFX_DATA_INIT
}


void CSetTerminalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetTerminalDlg)
	DDX_Check(pDX, IDC_AUTOWRAP_CHECK, m_fAutoWrap);
	DDX_Check(pDX, IDC_LOCALECHO_CHECK, m_fLocalEcho);
	DDX_Check(pDX, IDC_RECIEVELF_CHECK, m_fReceiveLF);
	DDX_Check(pDX, IDC_SENDLF_CHECK, m_fSendLF);
	DDX_CBIndex(pDX, IDC_TERMINAL_COMBO, m_nTerminal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetTerminalDlg, CDialog)
	//{{AFX_MSG_MAP(CSetTerminalDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetTerminalDlg message handlers
