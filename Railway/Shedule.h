#pragma once
#include "afxdb.h"


// CShedule dialog

class CShedule : public CDialogEx
{
	DECLARE_DYNAMIC(CShedule)

public:
	CShedule(CWnd* pParent = NULL);   // standard constructor
	virtual ~CShedule();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonopen();
	CDatabase db;
	CString zapros;
	void FillList(CString zapros);
	CListCtrl m_list;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtondelete();
	afx_msg void OnBnClickedButtoninsert();
	//afx_msg void OnBnClickedButtonsearch();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonupdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonrefresh();
	//afx_msg void OnBnClickedButtoncancelfilter();
};
