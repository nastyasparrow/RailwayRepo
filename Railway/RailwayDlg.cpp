
// RailwayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Railway.h"
#include "RailwayDlg.h"
#include "afxdialogex.h"
#include "Shedule.h"
#include "Shedule_User.h"
#include "FPassword.h"
#include "Registration.h"
#include "Admin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRailwayDlg dialog




CRailwayDlg::CRailwayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRailwayDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_login = _T("");
	m_password = _T("");
}

void CRailwayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_login);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}

BEGIN_MESSAGE_MAP(CRailwayDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRailwayDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CRailwayDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRailwayDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CRailwayDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CRailwayDlg message handlers

BOOL CRailwayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
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
	
	}
	else
		AfxMessageBox(L"Base not Open");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRailwayDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRailwayDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRailwayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRailwayDlg::OnBnClickedOk()
{
	CAdmin admin;
	CShedule_User user;
	CWnd::UpdateData(true);
	if((m_login=="admin")&&(m_password=="admin"))
		{
			CWnd::CloseWindow();
			admin.DoModal();
		}
	else
		{
			CWnd::CloseWindow();
			user.DoModal();
		}
	CWnd::UpdateData(false);
	CDialogEx::OnOK();
}

void CRailwayDlg::OnBnClickedButton1()
{
	CFPassword fpassword;
	fpassword.DoModal();
}


void CRailwayDlg::OnBnClickedButton2()
{
	CString m_login, m_password, m_confirmPassword, m_userName, m_userSurname, m_credCardNumber, m_passportData, m_phone, m_email, zapros;
	CRegistration registration;
	CWnd::UpdateData(true);
	while (registration.DoModal()==IDOK)
	{
		m_login=registration.m_login;
		m_password=registration.m_password;
		m_confirmPassword=registration.m_confirmPassword;
		m_userName=registration.m_userName;
		m_userSurname=registration.m_userSurname;
		m_credCardNumber=registration.m_credCardNumber;
		m_passportData=registration.m_passportData;
		m_phone=registration.m_phone;
		m_email=registration.m_email;

		if((m_login=="")||(m_password=="")||(m_confirmPassword=="")||(m_userName=="")||(m_userSurname=="")||(m_credCardNumber=="")||(m_passportData=="")||(m_phone=="")||(m_email==""))
			{
				AfxMessageBox(_T("Все поля должны быть заполнены!"));
				registration.DoModal();
				
			}
		else if(m_password!=m_confirmPassword)
				{
					AfxMessageBox(_T("Пароли не совпадают!"));
					registration.DoModal();
				}
		else
			{
				zapros.Format(_T("Insert into users values ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')"), m_login, m_password, m_userName, m_userSurname, m_credCardNumber, m_passportData, m_phone, m_email);
				db.ExecuteSQL(zapros);
				AfxMessageBox(_T("Вы успешно прошли регистрацию в системе заказа билетов на поезда!"));
				break;
			}
	}
	CWnd::UpdateData (false);
}


void CRailwayDlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}
