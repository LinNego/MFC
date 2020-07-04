#if !defined(AFX_SIGN_UP_H__D9C758F0_A729_4550_A45A_8631736348DB__INCLUDED_)
#define AFX_SIGN_UP_H__D9C758F0_A729_4550_A45A_8631736348DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SIGN_UP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SIGN_UP dialog

class SIGN_UP : public CDialog
{
// Construction
public:
	SIGN_UP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SIGN_UP)
	enum { IDD = IDD_SIGN_DIALOG };
	CString	m_account;
	CString	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SIGN_UP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SIGN_UP)
	afx_msg void OnOk();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL Build();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGN_UP_H__D9C758F0_A729_4550_A45A_8631736348DB__INCLUDED_)
