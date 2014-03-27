// Shedule_User.cpp : implementation file
//

#include "stdafx.h"
#include "Railway.h"
#include "RailwayDlg.h"
#include "Shedule_User.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "Search.h"
#include "RailwayDlg.h"
#include "TicketAgent.h"
#include "Order.h"

// CShedule_User dialog

IMPLEMENT_DYNAMIC(CShedule_User, CDialogEx)

CShedule_User::CShedule_User(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShedule_User::IDD, pParent)
	, zapros(_T(""))
{

}

CShedule_User::~CShedule_User()
{
}

void CShedule_User::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//GetDlgItem(IDC_BUTTONINSERT)->EnableWindow(false);
	//GetDlgItem(IDC_BUTTONDELETE)->EnableWindow(false);
	//GetDlgItem(IDC_BUTTONUPDATE)->EnableWindow(false);
}


BEGIN_MESSAGE_MAP(CShedule_User, CDialogEx)
	ON_BN_CLICKED(IDOK, &CShedule_User::OnBnClickedOk)
	//ON_BN_CLICKED(IDC_BUTTONSEARCH, &CShedule_User::OnBnClickedButtonsearch)
	//ON_BN_CLICKED(IDC_BUTTONCANCELFILTER, &CShedule_User::OnBnClickedButtoncancelfilter)
	//ON_BN_CLICKED(IDC_BUTTONUPDATE, &CShedule_User::OnBnClickedButtonupdate)
	ON_BN_CLICKED(IDC_BUTTONSELECTTRAIN, &CShedule_User::OnBnClickedButtonselecttrain)
	ON_BN_CLICKED(IDC_BUTTONTICKETAGENT, &CShedule_User::OnBnClickedButtonticketagent)
	ON_BN_CLICKED(IDC_BUTTONMAKEORDER, &CShedule_User::OnBnClickedButtonmakeorder)
END_MESSAGE_MAP()


void CShedule_User::FillList(CString zapros)
{
	int n,i;
	m_list.DeleteAllItems();
	n=m_list.GetHeaderCtrl()->GetItemCount();
	for(i=n-1;i>-1;i--)
	{
		m_list.DeleteColumn(i);
	}
	//m_list.SetTextColor(125); установка цвета
	CRecordset rec(&db);
	rec.Open(CRecordset::snapshot, zapros);
	int count=rec.GetODBCFieldCount();
	/*CODBCFieldInfo info;
	for (i=0;i<count;i++)
	{
		rec.GetODBCFieldInfo(i,info);
		m_list.InsertColumn(i,info.m_strName);
		m_list.SetColumnWidth(i,80);
	}*/
	CRect rc;
	m_list.GetWindowRect(&rc);
	m_list.InsertColumn(0, _T("№"), 0, rc.Width() / 8);
	m_list.InsertColumn(1, _T("Пункт відправлення"), 0, rc.Width() / 4); 
	m_list.InsertColumn(2, _T("Пункт прибуття"), 0, rc.Width() / 5);
	m_list.InsertColumn(3, _T("Час відправлення"), 0, rc.Width() / 5);
	m_list.InsertColumn(4, _T("Час прибуття"), 0, rc.Width() / 6);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);
			if(j == 0)
				m_list.InsertItem(i, buff);
			else
				m_list.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}


void CShedule_User::OnBnClickedOk()
{
	CDialogEx::OnOK();
	CRailwayDlg railwayDlg;
	railwayDlg.DoModal();
}


BOOL CShedule_User::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//open Baza
	CFileDialog dlg(true,NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"MS Access File (.mdb)|*.mdb||");
	CString ConnStr;
	if(dlg.DoModal() == IDOK)
	{
		//CString ConnStr;
		CString FilePath = dlg.GetPathName();
		ConnStr.Format(_T("ODBC;DRIVER={MICROSOFT ACCESS DRIVER (*.mdb)};DSN='';DBQ=%s"),FilePath);
		db.Open(NULL, FALSE, FALSE, ConnStr);
		/*zapros.Format(_T("SELECT * FROM railwayshedule ORDER BY departure_point"));
		FillList(zapros);*/
	}
	else
		AfxMessageBox(L"Base not Open");
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



//void CShedule_User::OnBnClickedButtonsearch()
//{
//	CSearch search;
//	if(search.DoModal()==IDOK)
//	{
//		if(search.m_radio==0)
//		{			
//			int number;
//			CString zapros;
//			CWnd::UpdateData(true);
//			number=search.m_number;
//			if(number==0)
//				{
//					AfxMessageBox(_T("Введіть номер потягу!"));
//				}
//			else
//				{
//					zapros.Format(_T("SELECT * FROM railwayshedule WHERE number=%d"),number);			
//					FillList(zapros);
//				}
//			CWnd::UpdateData(false);
//		}
//
//		
//		if(search.m_radio==1)
//		{					
//			CString zapros,station;
//			CWnd::UpdateData(true);
//			station=search.m_station;
//			if(station=="")
//				{
//					AfxMessageBox(_T("Введіть станцію!"));
//				}
//			else
//			{
//				zapros=_T("SELECT * FROM railwayshedule WHERE (departure_point LIKE '%")+station+_T("%') OR (arrival_point LIKE '%")+station+_T("%')");
//				db.ExecuteSQL(zapros);
//				FillList(zapros);
//			}
//			CWnd::UpdateData(false);
//		}
//
//		if(search.m_radio==2)
//		{					
//			CString zapros,deppoint,arrpoint;
//			CWnd::UpdateData(true);
//			deppoint=search.m_deppoint;
//			arrpoint=search.m_arrpoint;
//			if((deppoint=="")||(arrpoint==""))
//				{
//					AfxMessageBox(_T("Введіть пункти відправлення та прибуття!"));
//				}
//			else
//			{
//				zapros=_T("SELECT * FROM railwayshedule WHERE (departure_point LIKE '%")+deppoint+_T("%') AND (arrival_point LIKE '%")+arrpoint+_T("%')");
//				db.ExecuteSQL(zapros);			
//				FillList(zapros);
//			}
//			CWnd::UpdateData(false);
//		}
//	}
//}
//
//
//void CShedule_User::OnBnClickedButtoncancelfilter()
//{
//	zapros.Format(_T("SELECT * FROM railwayshedule ORDER BY departure_point"));
//	FillList(zapros);
//}
//
//
//void CShedule_User::OnBnClickedButtonupdate()
//{
//	// TODO: добавьте свой код обработчика уведомлений
//}


void CShedule_User::OnBnClickedButtonselecttrain()
{
	CSearch search;
	search.DoModal();
	/*if(search.DoModal()==IDOK)
	{
		if(search.m_radio==0)
		{			
			int number;
			CString zapros;
			CWnd::UpdateData(true);
			number=search.m_number;
			if(number==0)
			{
				AfxMessageBox(_T("Введите номер поезда!"));
			}
			else
			{
				zapros.Format(_T("SELECT * FROM railwayshedule WHERE number=%d"),number);			
				FillList(zapros);
			}
			CWnd::UpdateData(false);
		}
		
		if(search.m_radio==1)
		{					
			CString zapros,station;
			CWnd::UpdateData(true);
			station=search.m_station;
			if(station=="")
				{
					AfxMessageBox(_T("Введите станцию!"));
				}
			else
			{
				zapros=_T("SELECT * FROM railwayshedule WHERE (departure_point LIKE '%")+station+_T("%') OR (arrival_point LIKE '%")+station+_T("%')");
				db.ExecuteSQL(zapros);
				FillList(zapros);
			}
			CWnd::UpdateData(false);
		}

		if(search.m_radio==2)
		{					
			CString zapros,deppoint,arrpoint;
			CWnd::UpdateData(true);
			deppoint=search.m_deppoint;
			arrpoint=search.m_arrpoint;
			if((deppoint=="")||(arrpoint==""))
			{
				AfxMessageBox(_T("Введите пункти отправления и прибытия!"));
			}
			else
			{
				zapros=_T("SELECT * FROM railwayshedule WHERE (departure_point LIKE '%")+deppoint+_T("%') AND (arrival_point LIKE '%")+arrpoint+_T("%')");
				db.ExecuteSQL(zapros);			
				FillList(zapros);
			}
			CWnd::UpdateData(false);
		}
	}*/
}


void CShedule_User::OnBnClickedButtonticketagent()
{
	CTicketAgent ticketAgent;
	ticketAgent.DoModal();
}


void CShedule_User::OnBnClickedButtonmakeorder()
{
	COrder order;
	order.DoModal();
}
