#pragma once


// диалоговое окно CAdmin

class CAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CAdmin)

public:
	CAdmin(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CAdmin();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
