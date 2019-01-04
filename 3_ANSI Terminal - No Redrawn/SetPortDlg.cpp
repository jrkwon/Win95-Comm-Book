// SetPortDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hantle0.h"
// add for pDoc
#include "Hantle0Doc.h"

#include "SetPortDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPortDlg dialog


CSetPortDlg::CSetPortDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetPortDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CSetPortDlg)
    m_nBaudRate = -1;
    m_nDataBits = -1;
    m_fDTRDSR = FALSE;
    m_nParity = -1;
    m_nPort = -1;
    m_fRTSCTS = FALSE;
    m_nStopBits = -1;
    m_fXONXOFF = FALSE;
	//}}AFX_DATA_INIT

    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    // Get Comm Port
    CCommPort* pPort = pDoc->m_modem.GetCommPort();
    pPort->ReadProfile();

    m_nBaudRate = pPort->GetBaudRateIndex(pPort->GetBaudRate());
    m_nDataBits = pPort->GetDataBitsIndex(pPort->GetDataBits());
    m_fDTRDSR   = pPort->GetDTRDSR();
    m_nParity   = pPort->GetParityIndex(pPort->GetParity());
    m_nPort     = pPort->GetPort(); 
    m_fRTSCTS   = pPort->GetRTSCTS();
    m_nStopBits = pPort->GetStopBitsIndex(pPort->GetStopBits());
    m_fXONXOFF  = pPort->GetXONXOFF();
}


void CSetPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetPortDlg)
    DDX_CBIndex(pDX, IDC_BAUD_COMBO, m_nBaudRate);
    DDX_CBIndex(pDX, IDC_DATABITS_COMBO, m_nDataBits);
    DDX_Check(pDX, IDC_DTRDSR_CHECK, m_fDTRDSR);
    DDX_CBIndex(pDX, IDC_PARITY_COMBO, m_nParity);
    DDX_CBIndex(pDX, IDC_PORT_COMBO, m_nPort);
    DDX_Check(pDX, IDC_RTSCTS_CHECK, m_fRTSCTS);
    DDX_CBIndex(pDX, IDC_STOPBITS_COMBO, m_nStopBits);
    DDX_Check(pDX, IDC_XONXOFF_CHECK, m_fXONXOFF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetPortDlg, CDialog)
	//{{AFX_MSG_MAP(CSetPortDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPortDlg message handlers

void CSetPortDlg::OnOK() 
{
    // TODO: Add extra validation here

    CDialog::OnOK(); // UpdateData(TRUE)

    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    // Get Comm Port
    CCommPort* pPort = pDoc->m_modem.GetCommPort();

    pPort->SetBaudRate(dwBaudRateTable[m_nBaudRate]);
    pPort->SetDataBits(bDataBitsTable[m_nDataBits]);
    pPort->SetParity(bParityTable[m_nParity]);
    pPort->SetPort(portTable[m_nPort]);
    pPort->SetRTSCTS(m_fRTSCTS);
    pPort->SetStopBits(bStopBitsTable[m_nStopBits]);
    pPort->SetXONXOFF(m_fXONXOFF);
    pPort->SetDTRDSR(m_fDTRDSR);

    pPort->WriteProfile();
}

BOOL CSetPortDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
    CHantle0Doc* pDoc = (CHantle0Doc*)pFrameWnd->GetActiveDocument();

    // Get Comm Port
    CCommPort* pPort = pDoc->m_modem.GetCommPort();

    GetDlgItem(IDC_PORT_COMBO)->EnableWindow(!pPort->IsOpen());
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
