/*
 *	File:			TermANSI.h
 *
 *	Contains:		interface of the CTermANSI class
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

#ifndef _TERMANSI_H_
#define _TERMANSI_H_

// Max Ansi parameter
#define MAXANSIPARAM    10
#define NO_PARAM        -1

// ANSI state
typedef enum {
    CHAR_RCV_STATE, ESCAPE_RCV_STATE, PARAM_RCV_STATE
} ANSI_STATE;

// color index
typedef enum {
    BLACK_INDEX, RED_INDEX, GREEN_INDEX, YELLOW_INDEX, 
    BLUE_INDEX, MAGENTA_INDEX, CYAN_INDEX, WHITE_INDEX
} COLOR_INDEX;

extern COLORREF colorTable[];

class CTermANSI : public CObject
{
public: // create from serialization only
	CTermANSI();
	DECLARE_DYNCREATE(CTermANSI)

// Attributes
public:
    int      m_nParams[10];
    int      m_nCurParam;
    COLORREF m_colorText, m_colorInitText;
    COLORREF m_colorBk, m_colorInitBk;
    int      m_nOldRow;
    int      m_nOldCol;

// Operations
public:
    void GotoCursor();
    void CursorUp();
    void CursorDown();
    void CursorLeft();
    void CursorRight();
    void SaveCursorPos();
    void RestoreCursorPos();
    void ClearScreen();
    void ClearLine();
    void SetColor();
    BOOL Process(char cChar);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTermANSI)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTermANSI();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

#endif
/////////////////////////////////////////////////////////////////////////////
