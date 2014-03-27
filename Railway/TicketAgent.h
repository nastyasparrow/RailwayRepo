#pragma once


// диалоговое окно CTicketAgent

class CTicketAgent : public CDialogEx
{
	DECLARE_DYNAMIC(CTicketAgent)

public:
	CTicketAgent(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CTicketAgent();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
