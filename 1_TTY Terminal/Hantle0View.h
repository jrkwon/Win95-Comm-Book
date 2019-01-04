// Hantle0View.h : interface of the CHantle0View class
//
/////////////////////////////////////////////////////////////////////////////

class CHantle0View : public CView
{
protected: // create from serialization only
	CHantle0View();
	DECLARE_DYNCREATE(CHantle0View)

// Attributes
public:
	BOOL m_fCaret;

// Operations
public:
	void MoveCursor();
	void DisplayChar(BYTE bChar);
	void DisplayContent(LPSTR lpBlock, int nLength);

    CHantle0Doc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHantle0View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHantle0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHantle0View)
	afx_msg void OnPhoneConnect();
	afx_msg void OnPhoneDisconnect();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUpdatePhoneConnect(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePhoneDisconnect(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg LRESULT OnCommNotify(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Hantle0View.cpp
inline CHantle0Doc* CHantle0View::GetDocument()
   { return (CHantle0Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
