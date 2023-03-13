
// MFCRobotikaOtomasi.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCRobotikaOtomasiApp:
// See MFCRobotikaOtomasi.cpp for the implementation of this class
//

class CMFCRobotikaOtomasiApp : public CWinApp
{
public:
	CMFCRobotikaOtomasiApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCRobotikaOtomasiApp theApp;
