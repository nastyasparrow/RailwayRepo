#pragma once
#include "afxdb.h"

// CUpdate dialog

class CUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdate)

public:
	CUpdate(CWnd* pParent = NULL);   // standard constructor
	virtual ~CUpdate();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	int m_edit1;
	CString m_edit2;
	CString m_edit3;
//	CEdit m_edit4;
//	CString m_edit4;
//	CString m_edit5;
	CString m_edit1;
	afx_msg void OnBnClickedOk();
	CString m_edit4;
	CString m_edit5;
	CString m_edit6;
	CString m_edit7;
	CString m_edit8;
	CString m_edit9;
	CString m_edit10;
	CString m_edit11;
	CString m_edit12;
};
