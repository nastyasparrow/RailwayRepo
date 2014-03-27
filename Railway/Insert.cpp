// Insert.cpp : implementation file
//

#include "stdafx.h"
#include "Railway.h"
#include "Insert.h"
#include "afxdialogex.h"


// CInsert dialog

IMPLEMENT_DYNAMIC(CInsert, CDialogEx)

CInsert::CInsert(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsert::IDD, pParent)
	, m_number(0)
	, m_deptime(_T(""))
	, m_arrtime(_T(""))
	, m_date(_T(""))
	, m_freePlatzkart(_T(""))
	, m_freeCompartment(_T(""))
	, m_freeLux(_T(""))
	, m_pricePlatzkart(_T(""))
	, m_priceCompartment(_T(""))
	, m_priceLux(_T(""))
{

	m_number = 0;
	m_deppoint = _T("");
	m_arrpoint = _T("");
	//  m_deptime = _T("");
	//  m_arrtime = _T("");
}

CInsert::~CInsert()
{
}

void CInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	//  DDX_Control(pDX, IDC_EDIT2, m_deppoint);
	DDX_Text(pDX, IDC_EDIT2, m_deppoint);
	DDX_Text(pDX, IDC_EDIT3, m_arrpoint);
	//  DDX_Text(pDX, IDC_EDIT4, m_deptime);
	//  DDX_Text(pDX, IDC_EDIT5, m_arrtime);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT2, m_deptime);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT3, m_arrtime);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT1, m_date);
	DDX_Text(pDX, IDC_EDIT7, m_freePlatzkart);
	DDX_Text(pDX, IDC_EDIT8, m_freeCompartment);
	DDX_Text(pDX, IDC_EDIT9, m_freeLux);
	DDX_Text(pDX, IDC_EDIT10, m_pricePlatzkart);
	DDX_Text(pDX, IDC_EDIT11, m_priceCompartment);
	DDX_Text(pDX, IDC_EDIT12, m_priceLux);
}


BEGIN_MESSAGE_MAP(CInsert, CDialogEx)
END_MESSAGE_MAP()


// CInsert message handlers
