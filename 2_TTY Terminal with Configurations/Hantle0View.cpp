// Hantle0View.cpp : implementation of the CHantle0View class
//

#include "stdafx.h"
#include "Hantle0.h"

#include "Hantle0Doc.h"
#include "Hantle0View.h"

#include "SetPortDlg.h"
#include "SetTerminalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHantle0View

IMPLEMENT_DYNCREATE(CHantle0View, CView)

BEGIN_MESSAGE_MAP(CHantle0View, CView)
	//{{AFX_MSG_MAP(CHantle0View)
	ON_COMMAND(ID_PHONE_CONNECT, OnPhoneConnect)
	ON_COMMAND(ID_PHONE_DISCONNECT, OnPhoneDisconnect)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_CHAR()
	ON_UPDATE_COMMAND_UI(ID_PHONE_CONNECT, OnUpdatePhoneConnect)
	ON_UPDATE_COMMAND_UI(ID_PHONE_DISCONNECT, OnUpdatePhoneDisconnect)
	ON_COMMAND(ID_SET_PORT, OnSetPort)
	ON_COMMAND(ID_SET_TERMINAL, OnSetTerminal)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
    // user define message
    ON_MESSAGE(WM_COMMNOTIFY32, OnCommNotify)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHantle0View construction/destruction

CHantle0View::CHantle0View()
{
	// TODO: add construction code here
    m_fCaret = FALSE;

}

CHantle0View::~CHantle0View()
{
}

BOOL CHantle0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHantle0View drawing

void CHantle0View::OnDraw(CDC* pDC)
{
	CHantle0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
    HideCaret();
    pDC->SelectObject(GetStockObject(ANSI_FIXED_FONT));
    for(int nRow = 0; nRow < MAXTERMROW; nRow++)
    {
        int nBufferInRow = (nRow+pDoc->m_nScroll) % MAXTERMROW;
        pDC->TextOut(0, nRow*pDoc->m_charSize.cy, 
            (LPSTR)(pDoc->m_bScreen[nBufferInRow]), MAXTERMCOL);
    }
    ShowCaret();
    MoveCursor();
}

/////////////////////////////////////////////////////////////////////////////
// CHantle0View printing

BOOL CHantle0View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHantle0View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHantle0View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHantle0View diagnostics

#ifdef _DEBUG
void CHantle0View::AssertValid() const
{
	CView::AssertValid();
}

void CHantle0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHantle0Doc* CHantle0View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHantle0Doc)));
	return (CHantle0Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHantle0View message handlers

void CHantle0View::OnPhoneConnect() 
{
	// TODO: Add your command handler code here
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->m_modem.GetCommPort()->ReadProfile();
    pDoc->m_modem.GetCommPort()->SetPort(COM3);
    pDoc->m_modem.GetCommPort()->WriteProfile();

    pDoc->m_modem.GetCommPort()->SetNotifyWindow((HWND)this);
    
    AfxGetApp()->DoWaitCursor(1); // set hour glass cursor
    pDoc->m_modem.Open();
    AfxGetApp()->DoWaitCursor(0); // restore normal cursor
    SendMessage(WM_SETFOCUS);
}

void CHantle0View::OnPhoneDisconnect() 
{
	// TODO: Add your command handler code here
   	CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->m_modem.Close();
    SendMessage(WM_KILLFOCUS);
}

LRESULT CHantle0View::OnCommNotify(WPARAM wParam, LPARAM lParam)
{
   	CHantle0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    TRACE("Here is Comm Notify Hander !!\n");
    
    if(!pDoc->m_modem.GetCommPort()->IsOpen())
    {
        SetEvent(pDoc->m_modem.GetCommPort()->GetPostEvent());
        return FALSE;
    }
    if(LOWORD(lParam & CN_EVENT32) != CN_EVENT32)
    {
        SetEvent(pDoc->m_modem.GetCommPort()->GetPostEvent());
        return FALSE;
    }

    int nLength;
    BYTE abIn[MAXBUF+1];
    MSG msg;
    
	do
    {
        while(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
            AfxGetApp()->PumpMessage();

        if(nLength = pDoc->m_modem.GetCommPort()->Read((LPSTR)abIn, MAXBUF))
        {
            DisplayContent((LPSTR)abIn, nLength);
            UpdateWindow();
        }
    } while(nLength > 0);

    SetEvent(pDoc->m_modem.GetCommPort()->GetPostEvent());
    return TRUE;
}

void CHantle0View::DisplayContent(LPSTR lpBlock, int nLength)
{
    for(int i=0; i < nLength; i++)
    {
		DisplayChar(lpBlock[i]);
    } // for
}

void CHantle0View::DisplayChar(BYTE bChar)
{
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    switch(bChar)
    {
    case ASCII_BEL :
        MessageBeep(0);
        break;
    case ASCII_BS :
        if(pDoc->m_nCol > 0)
            pDoc->m_nCol--;
        break;
    case ASCII_TAB:
        if((pDoc->m_nCol/TABSTOP) < ((MAXTERMCOL-1)/TABSTOP))
        {
            pDoc->m_nCol += TABSTOP-pDoc->m_nCol%TABSTOP;
        }
        break;
    case ASCII_CR:
        pDoc->m_nCol = 0;
        break;
    case ASCII_LF:
        pDoc->m_nRow++;
        if(pDoc->m_nRow == MAXTERMROW) // last row in screen
        {
            pDoc->m_nRow--; 
            pDoc->m_nScroll++;
            pDoc->m_nScroll = (pDoc->m_nScroll) % MAXTERMROW;
            int nRow = (pDoc->m_nRow+pDoc->m_nScroll) % MAXTERMROW;
            memset(pDoc->m_bScreen[nRow], ' ', MAXTERMCOL);
            Invalidate(); // generate WM_PAINT, call OnDraw
        }
        break;
    default:
        int nRow = (pDoc->m_nRow+pDoc->m_nScroll) % MAXTERMROW;
        pDoc->m_bScreen[nRow][pDoc->m_nCol] = bChar;
        HideCaret();
        CDC *pDC = GetDC();
        pDC->SelectObject(GetStockObject(ANSI_FIXED_FONT));

        pDC->TextOut(pDoc->m_nCol*pDoc->m_charSize.cx, pDoc->m_nRow*pDoc->m_charSize.cy, (LPCTSTR)&bChar, 1);
        
        ReleaseDC(pDC);
        ShowCaret();
	    pDoc->m_nCol++;
        if(pDoc->m_nCol >= MAXTERMCOL)
        {
		    // auto wrap
            DisplayChar('\r');
            DisplayChar('\n');
        }
        break;
    } // switch
    MoveCursor();
}

void CHantle0View::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // if modem is open, show carets
    if(pDoc->m_modem.GetCommPort()->IsOpen())
    {
        ::CreateCaret(GetSafeHwnd(), NULL, pDoc->m_charSize.cx, pDoc->m_charSize.cy);
        ShowCaret();
        m_fCaret = TRUE;
        MoveCursor();
    }
}

void CHantle0View::OnKillFocus(CWnd* pNewWnd) 
{
	CView::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
    if(m_fCaret)
    {
        HideCaret();
        DestroyCaret();
        m_fCaret = FALSE;
    }
}

void CHantle0View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
	if(pDoc->m_modem.GetCommPort()->GetOpenFlag())
    {
        pDoc->m_modem.GetCommPort()->Write((BYTE)nChar);
        UpdateWindow();
    }
    else
	    CView::OnChar(nChar, nRepCnt, nFlags);
}

void CHantle0View::MoveCursor()
{
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if(m_fCaret)
    {
        POINT pt;
        pt.x = pDoc->m_nCol*pDoc->m_charSize.cx;
        pt.y = pDoc->m_nRow*pDoc->m_charSize.cy;
        SetCaretPos(pt);
    }
}

void CHantle0View::OnUpdatePhoneConnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

	pCmdUI->Enable(!pDoc->m_modem.GetCommPort()->IsOpen());
}

void CHantle0View::OnUpdatePhoneDisconnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    CHantle0Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

	pCmdUI->Enable(pDoc->m_modem.GetCommPort()->IsOpen());
}

void CHantle0View::OnSetPort() 
{
	// TODO: Add your command handler code here
	CSetPortDlg portDlg;
    portDlg.DoModal();
}

void CHantle0View::OnSetTerminal() 
{
	// TODO: Add your command handler code here
	CSetTerminalDlg termDlg;
    termDlg.DoModal();
}
