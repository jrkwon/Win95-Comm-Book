// SetTerminalDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetTerminalDlg dialog

class CSetTerminalDlg : public CDialog
{
// Construction
public:
	CSetTerminalDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetTerminalDlg)
	enum { IDD = IDD_SET_TERMINAL };
	BOOL	m_fAutoWrap;
	BOOL	m_fLocalEcho;
	BOOL	m_fReceiveLF;
	BOOL	m_fSendLF;
	int		m_nTerminal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetTerminalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetTerminalDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};