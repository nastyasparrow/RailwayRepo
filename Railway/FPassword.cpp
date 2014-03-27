// FPassword.cpp: файл реализации
//

#include "stdafx.h"
#include "Railway.h"
#include "FPassword.h"
#include "afxdialogex.h"


// диалоговое окно CFPassword

IMPLEMENT_DYNAMIC(CFPassword, CDialogEx)

CFPassword::CFPassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFPassword::IDD, pParent)
{

}

CFPassword::~CFPassword()
{
}

void CFPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFPassword, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFPassword::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CFPassword


void CFPassword::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
