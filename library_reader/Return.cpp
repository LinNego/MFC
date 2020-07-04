// Return.cpp : implementation file
//

#include "stdafx.h"
#include "library_reader.h"
#include "Return.h"
#include <afx.h>
#include <afxtempl.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Return dialog


Return::Return(CWnd* pParent /*=NULL*/)
	: CDialog(Return::IDD, pParent)
{
	//{{AFX_DATA_INIT(Return)
	m_isbn = _T("");
	//}}AFX_DATA_INIT
}


void Return::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Return)
	DDX_Text(pDX, IDC_EDIT1, m_isbn);
	DDV_MaxChars(pDX, m_isbn, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Return, CDialog)
	//{{AFX_MSG_MAP(Return)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Return message handlers

void Return::OnOK() 
{

	CDialog::OnOK();
	Build();
	ReBuild();
	MessageBox("还书成功");
}

void Return::Build()
{
	CMap<CString, LPCTSTR, CString, LPCTSTR> acc_isbn;
	//CMap<CString, LPCTSTR, CString, LPCTSTR> book_num;
	CStdioFile file;
	file.Open("account_isbn.dat", CFile::modeRead);
	CString line;
	while(file.ReadString(line))
	{
		CString s1, s2;
		int index = line.Find(' ');
		s1 = line.Mid(0, index);
		s2 = line.Mid(index + 1, line.GetLength() - index - 1);
		acc_isbn[s1] = s2;
	}
	file.Close();
	if(!acc_isbn.Lookup(user, line))
	{
		MessageBox("你没有借到书");
		return;
	}
	CString blank = " ";
	acc_isbn[user] = blank;
	file.Open("account_isbn.dat", CFile::modeCreate|CFile::modeWrite);
	POSITION pos = acc_isbn.GetStartPosition(); 
	while(pos != NULL)
	{
		CString s1, s2;
		acc_isbn.GetNextAssoc(pos, s1, s2);
		if(s2 != blank)
		{
			file.WriteString(s1);
			file.WriteString(" ");
			file.WriteString(s2 + "\n");
		}
	
	}
	file.Close();
	
}

void Return::ReBuild()
{
	CStdioFile file;
	CMap<CString, LPCTSTR, int, int&> book_num;
	file.Open("book.dat", CFile::modeRead);
	CString line;
	while(file.ReadString(line))
	{
		CString s1, s2;
		int index = line.Find(' ');
		s1 = line.Mid(0, index);
		s2 = line.Mid(index + 1, line.GetLength() - index - 1);
	//	MessageBox(s1);
		//MessageBox(s2);
		int num = _ttoi(s2);
		book_num[s1] = num;
	}
	book_num[m_isbn] += 1;
	file.Close();
	file.Open("book.dat", CFile::modeCreate|CFile::modeWrite);
	POSITION pos = book_num.GetStartPosition();
	while(pos)
	{
		CString s1, s2;
		int num;
	//	MessageBox(s1);
	//	MessageBox(s2);
		book_num.GetNextAssoc(pos, s1, num);
		s2.Format("%d", num);
		file.WriteString(s1);
		file.WriteString(" ");
		file.WriteString(s2 + "\n");
	}
	file.Close();
}
