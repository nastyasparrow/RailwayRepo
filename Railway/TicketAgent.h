#pragma once


// ���������� ���� CTicketAgent

class CTicketAgent : public CDialogEx
{
	DECLARE_DYNAMIC(CTicketAgent)

public:
	CTicketAgent(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CTicketAgent();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
};
