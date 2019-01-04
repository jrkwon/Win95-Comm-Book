// SetTerminalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hantle0.h"
#include "SetTerminalDlg.h"

#include "Hantle0Doc.h"
#include "Hantle0view.h"

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

    ReadProfile();
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
	ON_BN_CLICKED(IDC_FONT_BUTTON, OnFontButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetTerminalDlg message handlers

// section define
#define TERMINAL_SECTION	"Terminal Settings"

// item define
CString strTerminalItem[] = {
    "AutoWrap", "LocalEcho", "Insert LF before Receive Line", 
    "Insert LF after Send Line", "Terminal Emulate"
};
enum {
    ITEM_AUTOWRAP, ITEM_LOCALECHO, ITEM_RECEIVELF, ITEM_SENDLF, ITEM_TERMINAL
};


void CSetTerminalDlg::ReadProfile()
{
    CWinApp* pApp = AfxGetApp();

    m_fAutoWrap  = pApp->GetProfileInt(TERMINAL_SECTION, 
                        strTerminalItem[ITEM_AUTOWRAP], TRUE);
    m_fLocalEcho = pApp->GetProfileInt(TERMINAL_SECTION, 
                        strTerminalItem[ITEM_LOCALECHO], FALSE);
    m_fReceiveLF = pApp->GetProfileInt(TERMINAL_SECTION, 
                        strTerminalItem[ITEM_RECEIVELF], FALSE);
    m_fSendLF    = pApp->GetProfileInt(TERMINAL_SECTION, 
                        strTerminalItem[ITEM_SENDLF], FALSE);
    m_nTerminal  = pApp->GetProfileInt(TERMINAL_SECTION, 
                        strTerminalItem[ITEM_TERMINAL], TTY_TERM);

    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    pDoc->m_fAutoWrap = m_fAutoWrap;
    pDoc->m_fLocalEcho = m_fLocalEcho;
    pDoc->m_fReceiveLF = m_fReceiveLF;
    pDoc->m_fSendLF = m_fSendLF;
    pDoc->m_nTerminal = m_nTerminal;
}

void CSetTerminalDlg::WriteProfile()
{
    CWinApp* pApp = AfxGetApp();

    pApp->WriteProfileInt(TERMINAL_SECTION, 
                strTerminalItem[ITEM_AUTOWRAP], m_fAutoWrap);
    pApp->WriteProfileInt(TERMINAL_SECTION, 
                strTerminalItem[ITEM_LOCALECHO], m_fLocalEcho);
    pApp->WriteProfileInt(TERMINAL_SECTION, 
                strTerminalItem[ITEM_RECEIVELF], m_fReceiveLF);
    pApp->WriteProfileInt(TERMINAL_SECTION, 
                strTerminalItem[ITEM_SENDLF], m_fSendLF);
    pApp->WriteProfileInt(TERMINAL_SECTION, 
                strTerminalItem[ITEM_TERMINAL], m_nTerminal);
}


void CSetTerminalDlg::OnOK() 
{
    // TODO: Add extra validation here

    CDialog::OnOK(); // UpdateData

    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();
    
    pDoc->m_fAutoWrap = m_fAutoWrap;
    pDoc->m_fLocalEcho = m_fLocalEcho;
    pDoc->m_fReceiveLF = m_fReceiveLF;
    pDoc->m_fSendLF = m_fSendLF;
    pDoc->m_nTerminal = m_nTerminal;
    
    WriteProfile();

}

void CSetTerminalDlg::OnFontButton() 
{
	// TODO: Add your control notification handler code here
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();
    CHantle0View* pView = (CHantle0View*)pFrameWnd->GetActiveView();

   	LOGFONT newlf;

    newlf = pDoc->m_lfFont;
    CFontDialog fontDialog(&newlf, CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT | CF_FIXEDPITCHONLY);
    if(fontDialog.DoModal() == IDOK)
    {
        pDoc->m_lfFont = newlf;
        pDoc->SetCharSize(newlf);

        pView->Invalidate();

		pView->SetFont(&newlf);
    }
}
