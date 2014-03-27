// UserList.cpp: файл реализации
//

#include "stdafx.h"
#include "Railway.h"
#include "UserList.h"
#include "afxdialogex.h"



// диалоговое окно CUserList

IMPLEMENT_DYNAMIC(CUserList, CDialogEx)

CUserList::CUserList(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserList::IDD, pParent)
{

}

CUserList::~CUserList()
{
}

void CUserList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CUserList, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CUserList

void CUserList::FillList(CString zapros)
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
	m_list.InsertColumn(0, _T("Логин"), 0, rc.Width() / 8);
	m_list.InsertColumn(1, _T("Пароль"), 0, rc.Width() / 4); 
	m_list.InsertColumn(2, _T("Имя"), 0, rc.Width() / 5);
	m_list.InsertColumn(3, _T("Фамилия"), 0, rc.Width() / 4);
	m_list.InsertColumn(4, _T("Номер кредитной карты"), 0, rc.Width() / 6);
	m_list.InsertColumn(5, _T("Паспортные данные"), 0, rc.Width() / 6);
	m_list.InsertColumn(6, _T("Телефон"), 0, rc.Width() / 6);
	m_list.InsertColumn(7, _T("Email"), 0, rc.Width() / 6);
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

BOOL CUserList::OnInitDialog()
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
		zapros.Format(_T("SELECT * FROM users"));
		FillList(zapros);
	}
	else
		AfxMessageBox(L"Base not Open");

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
