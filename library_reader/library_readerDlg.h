// library_readerDlg.h : header file
//
#if !defined(AFX_LIBRARY_READERDLG_H__743EC3D6_C2B8_44B8_A097_F5FFCAE7DF27__INCLUDED_)
#define AFX_LIBRARY_READERDLG_H__743EC3D6_C2B8_44B8_A097_F5FFCAE7DF27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLibrary_readerDlg dialog
#include <fstream.h>
#include <afxtempl.h>
#include <afx.h>
#include "SIGN_UP.h"
#include "FUN.h"
class CLibrary_readerDlg : public CDialog
{
// Construction
public:
	CLibrary_readerDlg(CWnd* pParent = NULL);	// standard constructor
	~CLibrary_readerDlg() { delete fun; }
// Dialog Data
	//{{AFX_DATA(CLibrary_readerDlg)
	enum { IDD = IDD_LIBRARY_READER_DIALOG };
	CString	m_password;
	CString	m_user;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibrary_readerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLibrary_readerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSignUp();
	afx_msg void OnButtonSign();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	FUN *fun;
	CMap<CString, LPCTSTR, CString, LPCTSTR> acc_pass;
	void Build();
	BOOL built;
	CString user, password;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARY_READERDLG_H__743EC3D6_C2B8_44B8_A097_F5FFCAE7DF27__INCLUDED_)
