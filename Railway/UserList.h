#pragma once
#include "afxcmn.h"
#include "afxdb.h"


// ���������� ���� CUserList

class CUserList : public CDialogEx
{
	DECLARE_DYNAMIC(CUserList)

public:
	CUserList(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CUserList();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CDatabase db;
	CString zapros;
	void FillList(CString zapros);
	virtual BOOL OnInitDialog();
};
