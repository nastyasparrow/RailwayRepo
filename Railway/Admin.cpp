// Admin.cpp: файл реализации
//

#include "stdafx.h"
#include "Railway.h"
#include "Admin.h"
#include "afxdialogex.h"
#include "RailwayDlg.h"
#include "UserList.h"
#include "Shedule.h"


// диалоговое окно CAdmin

IMPLEMENT_DYNAMIC(CAdmin, CDialogEx)

CAdmin::CAdmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdmin::IDD, pParent)
{

}

CAdmin::~CAdmin()
{
}

void CAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdmin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAdmin::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdmin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdmin::OnBnClickedButton2)
END_MESSAGE_MAP()


// обработчики сообщений CAdmin


void CAdmin::OnBnClickedOk()
{
	CWnd::CloseWindow();
	CRailwayDlg railwayDlg;
	railwayDlg.DoModal();
	CDialogEx::OnOK();
}


void CAdmin::OnBnClickedButton1()
{
	CUserList userList;
	userList.DoModal();
}


void CAdmin::OnBnClickedButton2()
{
	CShedule shedule;
	shedule.DoModal();
}
