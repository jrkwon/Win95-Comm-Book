// Hantle0Doc.cpp : implementation of the CHantle0Doc class
//

#include "stdafx.h"
#include "Hantle0.h"

#include "Hantle0Doc.h"
#include "Hantle0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHantle0Doc

IMPLEMENT_DYNCREATE(CHantle0Doc, CDocument)

BEGIN_MESSAGE_MAP(CHantle0Doc, CDocument)
	//{{AFX_MSG_MAP(CHantle0Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHantle0Doc construction/destruction

CHantle0Doc::CHantle0Doc()
{
	// TODO: add one-time construction code here
}

CHantle0Doc::~CHantle0Doc()
{
}

BOOL CHantle0Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    
    // variable initialize
    memset(m_bScreen, ' ', MAXTERMROW*MAXTERMCOL);
    m_nRow = m_nCol = 0;
    m_nScroll = 0;
    
	// font initialize
    memset(&m_lfFont, 0, sizeof(m_lfFont));
    m_lfFont.lfHeight = -9;
    m_lfFont.lfWeight = FW_DONTCARE;
    m_lfFont.lfPitchAndFamily = FIXED_PITCH|FF_DONTCARE;
    strcpy(m_lfFont.lfFaceName, "Fixedsys");
    
    SetCharSize(m_lfFont);

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CHantle0Doc serialization

void CHantle0Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHantle0Doc diagnostics

#ifdef _DEBUG
void CHantle0Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHantle0Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHantle0Doc commands


void CHantle0Doc::SetCharSize(LOGFONT lfFont)
{
    // char size initialize
    POSITION firstViewPos;
    CHantle0View *pView;

    firstViewPos = GetFirstViewPosition();
    pView = (CHantle0View*)GetNextView(firstViewPos);

    CFont font, *pOldFont;
    font.CreateFontIndirect(&lfFont);

    TEXTMETRIC tm;
    CDC *pDC = pView->GetDC();
    pOldFont = pDC->SelectObject(&font);
    //pDC->SelectObject(GetStockObject(SYSTEM_FIXED_FONT));
    pDC->GetTextMetrics(&tm);

    m_charSize.cx = tm.tmAveCharWidth;
    m_charSize.cy = tm.tmHeight;

    pDC->SelectObject(pOldFont);
    pView->ReleaseDC(pDC);
}
