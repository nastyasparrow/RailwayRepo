#pragma once


// ���������� ���� CFPassword

class CFPassword : public CDialogEx
{
	DECLARE_DYNAMIC(CFPassword)

public:
	CFPassword(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CFPassword();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
