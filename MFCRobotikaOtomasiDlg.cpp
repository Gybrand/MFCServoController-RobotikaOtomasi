
// MFCRobotikaOtomasiDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCRobotikaOtomasi.h"
#include "MFCRobotikaOtomasiDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCRobotikaOtomasiDlg dialog



CMFCRobotikaOtomasiDlg::CMFCRobotikaOtomasiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCROBOTIKAOTOMASI_DIALOG, pParent)
	, m_value(0)
	, m_port(0)
	, m_y1(0)
	, m_y2(0)
	, m_interpolasi(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	sudut = 0;
	y = 0;
}

void CMFCRobotikaOtomasiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_comm);
	DDX_Text(pDX, IDC_EDIT1, m_value);
	DDX_Text(pDX, IDC_EDIT2, m_port);
	DDX_Text(pDX, IDC_EDIT3, m_y1);
	DDX_Text(pDX, IDC_EDIT4, m_y2);
	DDX_Text(pDX, IDC_EDIT5, m_interpolasi);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}

BEGIN_MESSAGE_MAP(CMFCRobotikaOtomasiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCRobotikaOtomasiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCRobotikaOtomasiDlg::OnBnClickedButton2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCRobotikaOtomasiDlg::OnNMCustomdrawSlider1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCRobotikaOtomasiDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCRobotikaOtomasiDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CMFCRobotikaOtomasiDlg message handlers

BOOL CMFCRobotikaOtomasiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//TODO: Add extra initialization here 
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_slider.SetRange(0, 180, 1);
	m_slider.SetPos(90);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCRobotikaOtomasiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCRobotikaOtomasiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCRobotikaOtomasiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCRobotikaOtomasiDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_comm.put_CommPort(m_port);
	UpdateData(0);
	m_comm.put_Settings(_T("115200,N,8,1"));
	m_comm.put_InputMode(0);
	m_comm.put_InputLen(1);
	m_comm.put_RTSEnable(TRUE);
	m_comm.put_RThreshold(1);
	m_comm.put_PortOpen(TRUE);
}


void CMFCRobotikaOtomasiDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_comm.put_PortOpen(FALSE);
}


void CMFCRobotikaOtomasiDlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData(1);
	sudut = m_slider.GetPos();
	m_value = sudut;
	y = m_y1 + (m_y2 - m_y1) * (sudut - 0) / (180 - 0);
	m_interpolasi = y;
	UpdateData(0);
	CByteArray hexdata; hexdata.SetSize(19);
	CByteArray header; header.SetSize(2);
	CByteArray tail; tail.SetSize(3);
	header[0] = 0x0D;
	header[1] = 0x0A;
	hexdata[0] = '#';
	hexdata[1] = '3';
	hexdata[2] = ' ';
	hexdata[3] = 'P';
	hexdata[4] = 0x30 + ((y / 1000) % 10);
	hexdata[5] = 0x30 + ((y / 100) % 10);
	hexdata[6] = 0x30 + ((y / 10) % 10);
	hexdata[7] = 0x30 + (y % 10);
	hexdata[8] = ' ';
	hexdata[9] = 'S';
	hexdata[10] = '1';
	hexdata[11] = '0';
	hexdata[12] = '0';
	hexdata[13] = '0';
	hexdata[14] = ' ';
	hexdata[15] = '<';
	hexdata[16] = 'c';
	hexdata[17] = 'r';
	hexdata[18] = '>';
	tail[0] = 0x0D;
	tail[1] = 0x0A;
	tail[2] = 0x00;
	if (m_comm.get_PortOpen()) {
		UpdateData(TRUE);
		m_comm.put_Output(COleVariant(header));
		m_comm.put_Output(COleVariant(hexdata));
		m_comm.put_Output(COleVariant(tail));
		UpdateData(FALSE);
	}
	*pResult = 0;
}


void CMFCRobotikaOtomasiDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCRobotikaOtomasiDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
