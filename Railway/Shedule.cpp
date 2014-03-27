// Shedule.cpp : implementation file
//

#include "stdafx.h"
#include "Railway.h"
#include "RailwayDlg.h"
#include "Shedule.h"
#include "afxdialogex.h"
#include "Insert.h"
#include "Search.h"
#include "Update.h"


// CShedule dialog

IMPLEMENT_DYNAMIC(CShedule, CDialogEx)

CShedule::CShedule(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShedule::IDD, pParent)
	, zapros(_T(""))
{

}

CShedule::~CShedule()
{
}

void CShedule::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CShedule, CDialogEx)
	ON_BN_CLICKED(IDOK, &CShedule::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CShedule::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTONDELETE, &CShedule::OnBnClickedButtondelete)
	ON_BN_CLICKED(IDC_BUTTONINSERT, &CShedule::OnBnClickedButtoninsert)
	//ON_BN_CLICKED(IDC_BUTTONSEARCH, &CShedule::OnBnClickedButtonsearch)
	ON_BN_CLICKED(IDC_BUTTONUPDATE, &CShedule::OnBnClickedButtonupdate)
	//ON_BN_CLICKED(IDC_BUTTONCANCELFILTER, &CShedule::OnBnClickedButtoncancelfilter)
END_MESSAGE_MAP()

// CShedule message handlers



void CShedule::FillList(CString zapros)
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
	m_list.InsertColumn(1, _T("Пункт отправления"), 0, rc.Width() / 4); 
	m_list.InsertColumn(2, _T("Пункт прибытия"), 0, rc.Width() / 5);
	m_list.InsertColumn(3, _T("Время отправления"), 0, rc.Width() / 4);
	m_list.InsertColumn(4, _T("Время прибытия"), 0, rc.Width() / 6);
	m_list.InsertColumn(5, _T("Свободно плацкарт"), 0, rc.Width() / 6);
	m_list.InsertColumn(6, _T("Свободно купе"), 0, rc.Width() / 6);
	m_list.InsertColumn(7, _T("Свободно люкс"), 0, rc.Width() / 6);
	m_list.InsertColumn(8, _T("Цена плацкарт"), 0, rc.Width() / 6);
	m_list.InsertColumn(9, _T("Цена купе"), 0, rc.Width() / 6);
	m_list.InsertColumn(10, _T("Цена люкс"), 0, rc.Width() / 6);
	m_list.InsertColumn(11, _T("Дата"), 0, rc.Width() / 6);
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


void CShedule::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CShedule::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CShedule::OnBnClickedButtondelete()
{
	int m_e1;
	CString train_number, zapros;
	m_e1=m_list.GetSelectedCount();
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	int npos;
	while(pos)
	{
		npos=m_list.GetNextSelectedItem(pos);	
		train_number=m_list.GetItemText(npos,0);
		zapros.Format(L"DELETE * FROM railwayshedule WHERE number = %s",train_number);
		db.ExecuteSQL(zapros);
		AfxMessageBox(_T("Потяг видалений зі списку"));
		zapros.Format(_T("SELECT * FROM railwayshedule ORDER BY departure_point"));
		FillList(zapros);
	}
}


void CShedule::OnBnClickedButtoninsert()
{
	int m_number;
	CString m_deppoint, m_arrpoint, m_deptime, m_arrtime, m_date, m_freePlatzkart, m_freeCompartment, m_freeLux, m_pricePlatzkart, m_priceCompartment, m_priceLux, zapros;
	CInsert insert;
	CWnd::UpdateData (true);
	if (insert.DoModal()==IDOK)
	{
		m_number=insert.m_number;
		m_deppoint=insert.m_deppoint;
		m_arrpoint=insert.m_arrpoint;
		m_deptime=insert.m_deptime;
		m_arrtime=insert.m_arrtime;
		m_date=insert.m_date;
		m_freePlatzkart=insert.m_freePlatzkart;
		m_freeCompartment=insert.m_freeCompartment;
		m_freeLux=insert.m_freeLux;
		m_pricePlatzkart=insert.m_pricePlatzkart;
		m_priceCompartment=insert.m_priceCompartment;
		m_priceLux=insert.m_priceLux;
		if((m_number==0)||(m_deppoint=="")||(m_arrpoint=="")||(m_deptime=="")||(m_arrtime=="")||(m_date=="")||(m_freePlatzkart=="")||(m_freeCompartment=="")||(m_freeLux=="")||(m_pricePlatzkart=="")||(m_priceCompartment=="")||(m_priceLux==""))
			{
				AfxMessageBox(_T("Всі поля повинні бути заповнені!"));
			}
		else
			{
				zapros.Format(_T("Insert into railwayshedule values ('%d', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')"), m_number, m_deppoint, m_arrpoint, m_deptime, m_arrtime, m_freePlatzkart, m_freeCompartment, m_freeLux, m_pricePlatzkart, m_priceCompartment, m_priceLux, m_date);
				db.ExecuteSQL(zapros);
				zapros.Format(_T("SELECT * FROM railwayshedule ORDER BY departure_point"));
				FillList(zapros);
				AfxMessageBox(_T("Потяг доданий у список"));
			}
	}
	CWnd::UpdateData (false);
}


//void CShedule::OnBnClickedButtonsearch()
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
//			{
//				AfxMessageBox(_T("Введіть номер потягу!"));
//			}
//			else
//			{
//				zapros.Format(_T("SELECT * FROM railwayshedule WHERE number=%d"),number);			
//				FillList(zapros);
//			}
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
//			{
//				AfxMessageBox(_T("Введіть пункти відправлення та прибуття!"));
//			}
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


BOOL CShedule::OnInitDialog()
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
		zapros.Format(_T("SELECT * FROM railwayshedule"));
		FillList(zapros);
	}
	else
		AfxMessageBox(L"Base not Open");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CShedule::OnBnClickedButtonupdate()
{
	CUpdate update;	
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	int npos=m_list.GetNextSelectedItem(pos);	
	update.m_edit1=m_list.GetItemText(npos,0);
	update.m_edit2=m_list.GetItemText(npos,1);
	update.m_edit3=m_list.GetItemText(npos,2);
	update.m_edit4=m_list.GetItemText(npos,3);
	update.m_edit5=m_list.GetItemText(npos,4);
	update.m_edit7=m_list.GetItemText(npos,5);
	update.m_edit8=m_list.GetItemText(npos,6);
	update.m_edit9=m_list.GetItemText(npos,7);
	update.m_edit10=m_list.GetItemText(npos,8);
	update.m_edit11=m_list.GetItemText(npos,9);
	update.m_edit12=m_list.GetItemText(npos,10);
	update.m_edit6=m_list.GetItemText(npos,11);
	if(update.DoModal()==IDOK)	
	{
		CString str,zapros;
		POSITION pos=m_list.GetFirstSelectedItemPosition();
		int npos;
		while(pos)
		{
			npos=m_list.GetNextSelectedItem(pos);	
			CString number=update.m_edit1;
			CString deppoint=update.m_edit2;
			CString arrpoint=update.m_edit3;
			CString deptime=update.m_edit4;
			CString arrtime=update.m_edit5;
			CString date=update.m_edit6;
			CString freePlatzkart=update.m_edit7;
			CString freeCompartment=update.m_edit8;
			CString freeLux=update.m_edit9;
			CString pricePlatzkart=update.m_edit10;
			CString priceCompartment=update.m_edit11;
			CString priceLux=update.m_edit12;

			zapros.Format(_T("UPDATE railwayshedule SET departure_point='%s', arrival_point='%s', departure_time='%s', arrival_time='%s', free_platzkart=='%s', free_comprtment='%s', free_lux='%s', price_platzkart='%s', price_compartment='%s', price_lux='%s', departure_date='%s', WHERE number = %s"),deppoint,arrpoint,deptime,arrtime,freePlatzkart,freeCompartment,freeLux,pricePlatzkart,priceCompartment,priceLux,date,number);
			db.ExecuteSQL(zapros);
			zapros.Format(_T("SELECT  * FROM railwayshedule ORDER BY departure_point"));
			FillList(zapros);
		}
	}	
}


//void CShedule::OnBnClickedButtoncancelfilter()
//{
//	zapros.Format(_T("SELECT * FROM railwayshedule ORDER BY departure_point"));
//	FillList(zapros);
//}
