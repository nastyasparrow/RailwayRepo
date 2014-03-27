#pragma once


// диалоговое окно CFPassword

class CFPassword : public CDialogEx
{
	DECLARE_DYNAMIC(CFPassword)

public:
	CFPassword(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CFPassword();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
