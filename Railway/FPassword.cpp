// FPassword.cpp: ���� ����������
//

#include "stdafx.h"
#include "Railway.h"
#include "FPassword.h"
#include "afxdialogex.h"


// ���������� ���� CFPassword

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


// ����������� ��������� CFPassword


void CFPassword::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnOK();
}
