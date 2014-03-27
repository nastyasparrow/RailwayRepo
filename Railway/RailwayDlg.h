
// RailwayDlg.h : header file
//

#pragma once
#include "afxdb.h"


// CRailwayDlg dialog
class CRailwayDlg : public CDialogEx
{
// Construction
public:
	CRailwayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_RAILWAY_DIALOG };

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
	CDatabase db;
	CString m_login;
	CString m_password;
	afx_msg void OnBnClickedOk();
	//CDatabase db;
	CString zapros;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
};
