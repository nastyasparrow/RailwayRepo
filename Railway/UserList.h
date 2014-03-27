#pragma once
#include "afxcmn.h"
#include "afxdb.h"


// диалоговое окно CUserList

class CUserList : public CDialogEx
{
	DECLARE_DYNAMIC(CUserList)

public:
	CUserList(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CUserList();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CDatabase db;
	CString zapros;
	void FillList(CString zapros);
	virtual BOOL OnInitDialog();
};
