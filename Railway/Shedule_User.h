#pragma once
#include "afxdb.h"

// CShedule_User dialog

class CShedule_User : public CDialogEx
{
	DECLARE_DYNAMIC(CShedule_User)

public:
	CShedule_User(CWnd* pParent = NULL);   // standard constructor
	virtual ~CShedule_User();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CDatabase db;
	CString zapros;
	void FillList(CString zapros);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtoninsert();
	//afx_msg void OnBnClickedButtonsearch();
	//afx_msg void OnBnClickedButtoncancelfilter();
	afx_msg void OnBnClickedButtondelete();
	//afx_msg void OnBnClickedButtonupdate();
	afx_msg void OnBnClickedButtonselecttrain();
	afx_msg void OnBnClickedButtonticketagent();
	afx_msg void OnBnClickedButtonmakeorder();
};
