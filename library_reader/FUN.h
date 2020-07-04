#if !defined(AFX_FUN_H__BF99C946_C98C_4CED_BA26_9D52296DDEBA__INCLUDED_)
#define AFX_FUN_H__BF99C946_C98C_4CED_BA26_9D52296DDEBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FUN.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FUN dialog
#include <afxtempl.h>
class FUN : public CDialog
{
// Construction
public:
	FUN(CWnd* pParent = NULL);// standard constructor
	~FUN();
	CString account;
// Dialog Data
	//{{AFX_DATA(FUN)
	enum { IDD = IDD_DIALOG_FUNCTION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(FUN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(FUN)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	FUN *fun;
	CMap<CString, LPCTSTR, CString, LPCTSTR> acc_isbn;
	void Build();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FUN_H__BF99C946_C98C_4CED_BA26_9D52296DDEBA__INCLUDED_)
