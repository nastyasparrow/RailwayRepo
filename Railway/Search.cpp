// Search.cpp : implementation file
//

#include "stdafx.h"
#include "Railway.h"
#include "Search.h"
#include "afxdialogex.h"


// CSearch dialog

IMPLEMENT_DYNAMIC(CSearch, CDialogEx)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearch::IDD, pParent)
{

	m_number = 0;
	m_station = _T("");
	m_deppoint = _T("");
	m_arrpoint = _T("");
	m_radio = 0;
}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Text(pDX, IDC_EDIT2, m_station);
	DDX_Text(pDX, IDC_EDIT3, m_deppoint);
	DDX_Text(pDX, IDC_EDIT4, m_arrpoint);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CSearch, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSearch::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTONREPLACE, &CSearch::OnBnClickedButtonreplace)
	ON_BN_CLICKED(IDC_BUTTON2, &CSearch::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSearch message handlers


void CSearch::FillList(CString zapros)
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

void CSearch::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void CSearch::OnBnClickedButtonreplace()
{
	CString temp,departurepoint,arrivalpoint;
	UpdateData(true);
	departurepoint=m_deppoint;
	arrivalpoint=m_arrpoint;
	temp=departurepoint;
	departurepoint=arrivalpoint;
	arrivalpoint=temp;
	m_deppoint=departurepoint;
	m_arrpoint=arrivalpoint;
	UpdateData(false);
}


BOOL CSearch::OnInitDialog()
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
		/*zapros.Format(_T("SELECT * FROM railwayshedule"));
		FillList(zapros);*/
	}
	else
		AfxMessageBox(L"Base not Open");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSearch::OnBnClickedButton2()
{
	if(m_radio==0)
		{			
			int number;
			CString zapros;
			CWnd::UpdateData(true);
			number=m_number;
			if(number==0)
			{
				AfxMessageBox(_T("Введіть номер потягу!"));
			}
			else
			{
				zapros.Format(_T("SELECT * FROM railwayshedule WHERE number=%d"),number);			
				FillList(zapros);
			}
			CWnd::UpdateData(false);
		}

		
		if(m_radio==1)
		{					
			CString zapros,station;
			CWnd::UpdateData(true);
			station=m_station;
			if(station=="")
				{
					AfxMessageBox(_T("Введіть станцію!"));
				}
			else
			{
				zapros=_T("SELECT * FROM railwayshedule WHERE (departure_point LIKE '%")+station+_T("%') OR (arrival_point LIKE '%")+station+_T("%')");
				db.ExecuteSQL(zapros);
				FillList(zapros);
			}
			CWnd::UpdateData(false);
		}

		if(m_radio==2)
		{					
			CString zapros,deppoint,arrpoint;
			CWnd::UpdateData(true);
			deppoint=m_deppoint;
			arrpoint=m_arrpoint;
			if((deppoint=="")||(arrpoint==""))
			{
				AfxMessageBox(_T("Введіть пункти відправлення та прибуття!"));
			}
			else
			{
				zapros=_T("SELECT * FROM railwayshedule WHERE (departure_point LIKE '%")+deppoint+_T("%') AND (arrival_point LIKE '%")+arrpoint+_T("%')");
				db.ExecuteSQL(zapros);			
				FillList(zapros);
			}
			CWnd::UpdateData(false);
		}
}
