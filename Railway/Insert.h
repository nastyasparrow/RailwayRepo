#pragma once


// CInsert dialog

class CInsert : public CDialogEx
{
	DECLARE_DYNAMIC(CInsert)

public:
	CInsert(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInsert();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	int m_number;
	int m_number;
//	CEdit m_deppoint;
	CString m_deppoint;
	CString m_arrpoint;
//	CString m_deptime;
//	CString m_arrtime;
	afx_msg void OnBnClickedCancel();
	CString m_deptime;
	CString m_arrtime;
	CString m_date;
	CString m_freePlatzkart;
	CString m_freeCompartment;
	CString m_freeLux;
	CString m_pricePlatzkart;
	CString m_priceCompartment;
	CString m_priceLux;
};
