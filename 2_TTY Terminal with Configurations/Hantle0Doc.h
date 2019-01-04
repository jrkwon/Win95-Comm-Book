// Hantle0Doc.h : interface of the CHantle0Doc class
//
/////////////////////////////////////////////////////////////////////////////

////////////////////////
// for serial comm class
#include "Modem.h"

#define MAXTERMCOL	80
#define MAXTERMROW	25

#define TABSTOP	8

class CHantle0Doc : public CDocument
{
protected: // create from serialization only
	CHantle0Doc();
	DECLARE_DYNCREATE(CHantle0Doc)

// Attributes
public:
    CModem  m_modem;
	BYTE    m_bScreen[MAXTERMROW][MAXTERMCOL];
    int     m_nRow;
    int     m_nCol;
	int		m_nScroll;
    CSize   m_charSize;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHantle0Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHantle0Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHantle0Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
