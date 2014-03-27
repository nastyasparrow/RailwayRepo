#pragma once


// ���������� ���� CRegistration

class CRegistration : public CDialogEx
{
	DECLARE_DYNAMIC(CRegistration)

public:
	CRegistration(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CRegistration();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_login;
	CString m_password;
	CString m_confirmPassword;
	CString m_userName;
	CString m_userSurname;
//	CString m_credCardNumbar;
	CString m_passportData;
	CString m_phone;
	CString m_email;
	CString m_credCardNumber;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
