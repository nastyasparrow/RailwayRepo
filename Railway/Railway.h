
// Railway.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CRailwayApp:
// See Railway.cpp for the implementation of this class
//

class CRailwayApp : public CWinApp
{
public:
	CRailwayApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CRailwayApp theApp;