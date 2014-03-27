// TicketAgent.cpp: файл реализации
//

#include "stdafx.h"
#include "Railway.h"
#include "TicketAgent.h"
#include "afxdialogex.h"


// диалоговое окно CTicketAgent

IMPLEMENT_DYNAMIC(CTicketAgent, CDialogEx)

CTicketAgent::CTicketAgent(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTicketAgent::IDD, pParent)
{

}

CTicketAgent::~CTicketAgent()
{
}

void CTicketAgent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTicketAgent, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CTicketAgent
