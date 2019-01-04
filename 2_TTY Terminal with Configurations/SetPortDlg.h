// SetPortDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetPortDlg dialog

class CSetPortDlg : public CDialog
{
// Construction
public:
	CSetPortDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetPortDlg)
	enum { IDD = IDD_SET_PORT };
	int		m_nBaudRate;
	int		m_nDataBits;
	BOOL	m_fDTRDSR;
	int		m_nParity;
	int		m_nPort;
	BOOL	m_fRTSCTS;
	int		m_nStopBits;
	BOOL	m_fXONXOFF;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetPortDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetPortDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
