
// MFCRobotikaOtomasiDlg.h : header file
//

#pragma once
#include "CMSCOMM1.h"


// CMFCRobotikaOtomasiDlg dialog
class CMFCRobotikaOtomasiDlg : public CDialogEx
{
// Construction
public:
	CMFCRobotikaOtomasiDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCROBOTIKAOTOMASI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMSCOMM1 m_comm;
	int m_value;
	int m_port;
	int m_y1;
	int m_y2;
	int m_interpolasi;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl m_slider;
	int sudut;
	int y;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
