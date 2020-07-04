// SIGN_UP.cpp : implementation file
//

#include "stdafx.h"
#include "library_reader.h"
#include <afx.h>
#include "SIGN_UP.h"
#include <afxtempl.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SIGN_UP dialog


SIGN_UP::SIGN_UP(CWnd* pParent /*=NULL*/)
	: CDialog(SIGN_UP::IDD, pParent)
{
	//{{AFX_DATA_INIT(SIGN_UP)
	m_account = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void SIGN_UP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SIGN_UP)
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, m_account);
	DDV_MaxChars(pDX, m_account, 30);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SIGN_UP, CDialog)
	//{{AFX_MSG_MAP(SIGN_UP)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
BOOL SIGN_UP::Build()
{
	CMap<CString, LPCTSTR, CString, LPCTSTR> temp;
	CStdioFile file;
	file.Open("account.dat", CFile::modeRead);
	CString line;
	while(file.ReadString(line))
	{	CString s1, s2;
		int index = line.Find(' ');	
		s1 = line.Mid(0, index);
		s2 = line.Mid(index + 1, line.GetLength() - index - 1);
		temp[s1] = s2;

	}
	file.Close();
	CString t;
	if(temp.Lookup(m_account, t))
	{
		MessageBox("用户名已经被注册");
		return false;
	
	}
	return true;
}// SIGN_UP message handlers




void SIGN_UP::OnOk() 
{
	
	CDialog::OnOK();
	CString user, password;
	if(!Build()) return ;
	user.Format(m_account);
	password.Format(m_password);
	MessageBox(user);
	MessageBox(password);
	CStdioFile file;
	file.Open("account.dat", CFile::modeWrite);
	file.SeekToEnd();
	//file.WriteString("\n");
	file.WriteString(user + ' ');
	file.WriteString(password + '\n');
	file.Close();
	//file.Open("account_isbn.dat", CFile::modeWrite);
	//file.SeekToEnd();
	//file.WriteString(user);
	// TODO: Add your control notification handler code here
	
}

void SIGN_UP::OnCancel() 
{
	CDialog::OnCancel();
	// TODO: Add your control notification handler code here
	
}
