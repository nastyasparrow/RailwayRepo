#pragma once


// ���������� ���� COrder

class COrder : public CDialogEx
{
	DECLARE_DYNAMIC(COrder)

public:
	COrder(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~COrder();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

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
