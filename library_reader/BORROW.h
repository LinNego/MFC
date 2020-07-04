#if !defined(AFX_BORROW_H__B5646E08_6F6C_4C18_9478_4BA9C2548992__INCLUDED_)
#define AFX_BORROW_H__B5646E08_6F6C_4C18_9478_4BA9C2548992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BORROW.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BORROW dialog
#include <afxtempl.h>
class BORROW : public CDialog
{
// Construction
public:
	CString account;
	BORROW(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BORROW)
	enum { IDD = IDD_DIALOG_BORROW };
	CString	m_isbn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BORROW)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BORROW)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Build();
	CMap<CString, LPCTSTR, int, int&> book_num;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROW_H__B5646E08_6F6C_4C18_9478_4BA9C2548992__INCLUDED_)
