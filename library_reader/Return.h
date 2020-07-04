#if !defined(AFX_RETURN_H__BC558E47_FAC8_45B7_AE2F_7A30AAC7B1B2__INCLUDED_)
#define AFX_RETURN_H__BC558E47_FAC8_45B7_AE2F_7A30AAC7B1B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Return.h : header file
//
#include <afx.h>
#include <afxtempl.h>
/////////////////////////////////////////////////////////////////////////////
// Return dialog

class Return : public CDialog
{
// Construction
public:
	Return(CWnd* pParent = NULL);   // standard constructor
	CString user;
// Dialog Data
	//{{AFX_DATA(Return)
	enum { IDD = IDD_DIALOG1 };
	CString	m_isbn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Return)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Return)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

		
private:
	void ReBuild();
	void Build();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURN_H__BC558E47_FAC8_45B7_AE2F_7A30AAC7B1B2__INCLUDED_)
