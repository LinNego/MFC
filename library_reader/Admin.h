#if !defined(AFX_ADMIN_H__DCE0C89D_7DB9_4D2C_A9A1_9B3701DDDFE4__INCLUDED_)
#define AFX_ADMIN_H__DCE0C89D_7DB9_4D2C_A9A1_9B3701DDDFE4__INCLUDED_
#include <afx.h>
#include <afxtempl.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Admin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Admin dialog

class Admin : public CDialog
{
// Construction
public:
	Admin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Admin)
	enum { IDD = IDD_DIALOG2 };
	CListBox	m_admin;
	CString	m_isbn;
	CString	m_num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Admin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Admin)
	afx_msg void OnSelchangeList1();
	virtual void OnOK();
	afx_msg void Ondelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void afterBuild();
	void preBuild();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMIN_H__DCE0C89D_7DB9_4D2C_A9A1_9B3701DDDFE4__INCLUDED_)
