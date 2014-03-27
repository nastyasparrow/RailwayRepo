#pragma once
#include "afxdb.h"
#include "afxwin.h"
#include "afxcmn.h"

// CSearch dialog

class CSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSearch();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CDatabase db;
	CString zapros;
	void FillList(CString zapros);
	int m_number;
	CString m_station;
	CString m_deppoint;
	CString m_arrpoint;
	int m_radio;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonreplace();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedSplit1();
	CComboBox m_ticketType;
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_list;
};
