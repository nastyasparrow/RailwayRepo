// Update.cpp : implementation file
//

#include "stdafx.h"
#include "Railway.h"
#include "Update.h"
#include "afxdialogex.h"


// CUpdate dialog

IMPLEMENT_DYNAMIC(CUpdate, CDialogEx)

CUpdate::CUpdate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUpdate::IDD, pParent)
	, m_edit4(_T(""))
	, m_edit5(_T(""))
	, m_edit6(_T(""))
	, m_edit7(_T(""))
	, m_edit8(_T(""))
	, m_edit9(_T(""))
	, m_edit10(_T(""))
	, m_edit11(_T(""))
	, m_edit12(_T(""))
{

	//  m_edit1 = 0;
	m_edit2 = _T("");
	m_edit3 = _T("");
	//  m_edit4 = _T("");
	//  m_edit5 = _T("");
	m_edit1 = _T("");
}

CUpdate::~CUpdate()
{
}

void CUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//  DDX_Control(pDX, IDC_EDIT4, m_edit4);
	//  DDX_Text(pDX, IDC_EDIT4, m_edit4);
	//  DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT2, m_edit4);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT3, m_edit5);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT1, m_edit6);
	DDX_Text(pDX, IDC_EDIT7, m_edit7);
	DDX_Text(pDX, IDC_EDIT8, m_edit8);
	DDX_Text(pDX, IDC_EDIT9, m_edit9);
	DDX_Text(pDX, IDC_EDIT10, m_edit10);
	DDX_Text(pDX, IDC_EDIT11, m_edit11);
	DDX_Text(pDX, IDC_EDIT12, m_edit12);
}


BEGIN_MESSAGE_MAP(CUpdate, CDialogEx)
	ON_BN_CLICKED(IDOK, &CUpdate::OnBnClickedOk)
END_MESSAGE_MAP()


// CUpdate message handlers


void CUpdate::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
