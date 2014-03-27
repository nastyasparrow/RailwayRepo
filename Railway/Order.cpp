// Order.cpp: файл реализации
//

#include "stdafx.h"
#include "Railway.h"
#include "Order.h"
#include "afxdialogex.h"


// диалоговое окно COrder

IMPLEMENT_DYNAMIC(COrder, CDialogEx)

COrder::COrder(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrder::IDD, pParent)
	, m_deppoint(_T(""))
	, m_arrpoint(_T(""))
	, m_deptime(_T(""))
	, m_arrtime(_T(""))
	, m_tickettype(_T(""))
	, m_ticketamount(0)
	, m_summary(_T(""))
{

}

COrder::~COrder()
{
}

void COrder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_deppoint);
	DDX_Text(pDX, IDC_EDIT2, m_arrpoint);
	DDX_Text(pDX, IDC_EDIT3, m_deptime);
	DDX_Text(pDX, IDC_EDIT4, m_arrtime);
	DDX_Text(pDX, IDC_EDIT5, m_tickettype);
	DDX_Text(pDX, IDC_EDIT6, m_ticketamount);
	DDX_Text(pDX, IDC_EDIT7, m_summary);
}


BEGIN_MESSAGE_MAP(COrder, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений COrder
