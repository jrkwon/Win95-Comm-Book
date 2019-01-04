// TermANSI.cpp : implementation of the CTermANSI class
//

#include "stdafx.h"
#include "TermANSI.h"

#include "Hantle0Doc.h"
#include "Hantle0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CTermANSI, CObject)

COLORREF colorTable[] = {
    RGB(0,0,0),         // BLACK
    RGB(255,0,0),       // RED
    RGB(0,255,0),       // GREEN
    RGB(0,0,255),       // BLUE
    RGB(255,255,0),     // YELLOW
    RGB(255,0,255),     // MAGENTA
    RGB(0,255,255),     // CYAN
    RGB(255,255,255)    // WHITE
};

CTermANSI::CTermANSI()
{
    m_colorInitText = m_colorText = colorTable[WHITE_INDEX];
    m_colorInitBk = m_colorBk = colorTable[BLACK_INDEX];
}

CTermANSI::~CTermANSI()
{
}

void CTermANSI::GotoCursor()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    if(m_nParams[0] == NO_PARAM)
    {
        pDoc->m_nCol = pDoc->m_nRow = 0;
    }
    else
    {
        pDoc->m_nCol = (m_nParams[1] == NO_PARAM) ? 0 : m_nParams[1]-1;
        pDoc->m_nRow = m_nParams[0]-1;
    }
}

void CTermANSI::CursorUp()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    pDoc->m_nRow -= (m_nParams[0] == NO_PARAM) ? 1 : m_nParams[0];
    pDoc->m_nRow = (pDoc->m_nRow < 0) ? 0 : pDoc->m_nRow;
}

void CTermANSI::CursorDown()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    pDoc->m_nRow += (m_nParams[0] == NO_PARAM) ? 1 : m_nParams[0];
    pDoc->m_nRow = (pDoc->m_nRow >= MAXTERMROW) ? MAXTERMROW-1 : pDoc->m_nRow;
}

void CTermANSI::CursorLeft()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    pDoc->m_nCol -= (m_nParams[0] == NO_PARAM) ? 1 : m_nParams[0]-1;
    pDoc->m_nCol = (pDoc->m_nCol < 0) ? 0 : pDoc->m_nCol;
}

void CTermANSI::CursorRight()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    pDoc->m_nCol += (m_nParams[0] == NO_PARAM) ? 1 : m_nParams[0]-1;
    pDoc->m_nCol = (pDoc->m_nCol >= MAXTERMCOL) ? MAXTERMCOL-1 : pDoc->m_nCol;
}

void CTermANSI::SaveCursorPos()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    m_nOldCol = pDoc->m_nCol;
    m_nOldRow = pDoc->m_nRow;
}

void CTermANSI::RestoreCursorPos()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    pDoc->m_nCol = m_nOldCol;
    pDoc->m_nRow = m_nOldRow;
}

void CTermANSI::ClearScreen()
{
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();
    CHantle0View* pView = (CHantle0View*)pFrameWnd->GetActiveView();

    pDoc->m_nCol = pDoc->m_nRow = 0;
    pDoc->m_nScroll = 0;
    memset(pDoc->m_bScreen, ' ', MAXTERMROW*MAXTERMCOL);
    pDoc->BackDCSolidFill();
    pView->Invalidate();
}

void CTermANSI::ClearLine()
{
}

void CTermANSI::SetColor()
{
	if(m_nParams[0] == -1)
	{
		m_colorText = m_colorInitText;
		m_colorBk = m_colorInitBk;
	}
	else {
		for(int i=0; i <= m_nCurParam && m_nParams[i] != -1; i++)
		{
			switch(m_nParams[i])
			{
			case 0 : // Reset 
				m_colorText = m_colorInitText;
				m_colorBk = m_colorInitBk;
				break;
			case 1 : // Bold
				break;
			case 4 : // Underline
				break;
			case 5 :
				break;
			case 7 : // Reverse
				{
					COLORREF colorTemp = m_colorText;
					m_colorText = m_colorBk;
					m_colorBk = colorTemp;
				}
				break;
			case 8 : // 
				m_colorText = m_colorBk;
				break;
			}
			if(m_nParams[i] >= 30 && m_nParams[i] <= 37)
				m_colorText = colorTable[m_nParams[i]-30];
			if(m_nParams[i] >= 40 && m_nParams[i] <= 47)
				m_colorText = colorTable[m_nParams[i]-40];
		}
	}
}

// return true when ansi process end
BOOL CTermANSI::Process(char cChar)
{
    switch(cChar) 
    {
    case 'H': // move cursor
    case 'f': // move cursor
        GotoCursor();
        break;
    case 'A': // move cursor line up 
        CursorUp();
        break;
    case 'B': // move cursor line down
        CursorDown();
        break;
    case 'C': // move cursor column right
        CursorRight();
        break;
    case 'D': // move cursor column left
        CursorLeft();
        break;
    case 's': // save the cursor position
        SaveCursorPos();
        break;
    case 'u': // restore the cursor position
        RestoreCursorPos();
        break;
    case 'J': // clear the screen
        ClearScreen();
        break;
    case 'K': // clear the current line
        ClearLine();
        break;
    case 'm': // set color
        SetColor();
        break;
    case 'h': // select screen mode
        break;
    case 'l': // restor screen mode
        break;
    case ';': 
        m_nCurParam++;
        m_nParams[m_nCurParam] = NO_PARAM;
        return FALSE;
    default:
        if(isdigit(cChar))
        {
            if(m_nParams[m_nCurParam] == NO_PARAM)
                m_nParams[m_nCurParam] = 0;
            else
                m_nParams[m_nCurParam] *= 10;
            m_nParams[m_nCurParam] += (cChar - '0');
        }
        else
            break;
        return FALSE;
    } // switch
    return TRUE; // process command
}

/////////////////////////////////////////////////////////////////////////////
// CTermANSI diagnostics

#ifdef _DEBUG
void CTermANSI::AssertValid() const
{
	CObject::AssertValid();
}

void CTermANSI::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
