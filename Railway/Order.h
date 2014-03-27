#pragma once


// диалоговое окно COrder

class COrder : public CDialogEx
{
	DECLARE_DYNAMIC(COrder)

public:
	COrder(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~COrder();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_deppoint;
	CString m_arrpoint;
	CString m_deptime;
	CString m_arrtime;
	CString m_tickettype;
	int m_ticketamount;
	CString m_summary;
};
