// library_reader.h : main header file for the LIBRARY_READER application
//

#if !defined(AFX_LIBRARY_READER_H__5E2747C6_AA41_43B4_B54C_65E8BCC854E9__INCLUDED_)
#define AFX_LIBRARY_READER_H__5E2747C6_AA41_43B4_B54C_65E8BCC854E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibrary_readerApp:
// See library_reader.cpp for the implementation of this class
//
//定义两个具有外部链接器的变量
class reader
{
	CString account, password;
	CString isbn[100];

};
class CLibrary_readerApp : public CWinApp
{
public:
	CLibrary_readerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibrary_readerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLibrary_readerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARY_READER_H__5E2747C6_AA41_43B4_B54C_65E8BCC854E9__INCLUDED_)
