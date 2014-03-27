// Registration.cpp: файл реализации
//

#include "stdafx.h"
#include "Railway.h"
#include "Registration.h"
#include "afxdialogex.h"
#include "RailwayDlg.h"


// диалоговое окно CRegistration

IMPLEMENT_DYNAMIC(CRegistration, CDialogEx)

CRegistration::CRegistration(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegistration::IDD, pParent)
	, m_login(_T(""))
	, m_password(_T(""))
	, m_confirmPassword(_T(""))
	, m_userName(_T(""))
	, m_userSurname(_T(""))
	, m_passportData(_T(""))
	, m_phone(_T(""))
	, m_email(_T(""))
	, m_credCardNumber(_T(""))
{

}

CRegistration::~CRegistration()
{
}

void CRegistration::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_login);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDX_Text(pDX, IDC_EDIT3, m_confirmPassword);
	DDX_Text(pDX, IDC_EDIT4, m_userName);
	DDX_Text(pDX, IDC_EDIT5, m_userSurname);
	DDX_Text(pDX, IDC_EDIT7, m_passportData);
	DDV_MaxChars(pDX, m_passportData, 8);
	DDX_Text(pDX, IDC_EDIT8, m_phone);
	DDV_MaxChars(pDX, m_phone, 15);
	DDX_Text(pDX, IDC_EDIT9, m_email);
	DDX_Text(pDX, IDC_EDIT6, m_credCardNumber);
	DDV_MaxChars(pDX, m_credCardNumber, 16);
}


BEGIN_MESSAGE_MAP(CRegistration, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CRegistration::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CRegistration::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CRegistration


void CRegistration::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
	CRailwayDlg railwaydlg;
	railwaydlg.DoModal();
}


void CRegistration::OnBnClickedOk()
{

	CDialogEx::OnOK();
}
