// Admin.cpp : implementation file
//

#include "stdafx.h"
#include "library_reader.h"
#include "Admin.h"
#include <afx.h>
#include <afxtempl.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Admin dialog


Admin::Admin(CWnd* pParent /*=NULL*/)
	: CDialog(Admin::IDD, pParent)
{
	//{{AFX_DATA_INIT(Admin)
	m_isbn = _T("");
	m_num = _T("");
	//}}AFX_DATA_INIT
	
}


void Admin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Admin)
	
	DDX_Text(pDX, IDC_isbn, m_isbn);
	DDV_MaxChars(pDX, m_isbn, 30);
	DDX_Text(pDX, IDC_num, m_num);
	DDV_MaxChars(pDX, m_num, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Admin, CDialog)
	//{{AFX_MSG_MAP(Admin)
	ON_BN_CLICKED(IDC_BUTTON2, Ondelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Admin message handlers





void Admin::OnOK() 
{
	
	CDialog::OnOK();
	CMap<CString, LPCTSTR, int, int&> book_number;
	
	CStdioFile file;
	file.Open("book.dat", CFile::modeRead);
	CString line;
	CString book, number;
	while(file.ReadString(line))
	{
		int index = line.Find(' ');
		book = line.Mid(0, index);
		number = line.Mid(index + 1, line.GetLength() - index - 1);
		int s_i = atoi(number);
		book_number[book] = s_i;
		//MessageBox(book);
	}
	file.Close();
	CString isbn, cnum;
//	UpdateData();
	isbn.Format(m_isbn);
	cnum.Format(m_num);
	CString ss;
	int num = _ttoi(cnum); 
	int temp;
	if(book_number.Lookup(isbn, temp))
	{
		book_number[isbn] = book_number[isbn] +  num;
		CString s;
		s.Format("%d", book_number[isbn]);
		MessageBox(s);
	
	
	}
	file.Open("book.dat", CFile::modeCreate|CFile::modeWrite);
	
	POSITION pos = book_number.GetStartPosition();
	while(pos != NULL)
	{
		CString book_isbn;
		int nums;
		book_number.GetNextAssoc(pos, book_isbn, nums);
		MessageBox(book_isbn);
		cnum.Format("%d", nums);
		//book = book + cnum;
		file.WriteString(book);
		//MessageBox(cnum);
		file.WriteString(" ");
		file.WriteString(cnum + "\n");
	
	}
	// TODO: Add extra validation here
	file.Close();
	
}

void Admin::Ondelete() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
	CMap<CString, LPCTSTR, int, int&> book_num;
	UpdateData();
	CStdioFile file;
	file.Open("book.dat", CFile::modeRead);
	CString line;
	CString book, number;
	while(file.ReadString(line))
	{
		int index = line.Find(' ');
		book = line.Mid(0, index);
		number = line.Mid(index + 1, line.GetLength() - index - 1);
		int s_i = atoi(number);
		book_num[book] = s_i;
	//	MessageBox(book);
	}
	file.Close();
	CString isbn, cnum;
	
	isbn.Format(m_isbn);
	cnum.Format(m_num);
	int num = _ttoi(cnum); 
	int temp;
	if(!book_num.Lookup(isbn, temp))
	{
		MessageBox("没有找到这本书.");
	
	}
	else if(book_num[isbn] < num)
	{
		book_num[isbn] = 0;
	
	}else
	{
		book_num[isbn] -= num;
	}
	file.Open("book.dat", CFile::modeCreate|CFile::modeWrite);
	POSITION pos = book_num.GetStartPosition();
	CString book_isbn;
	int nums;
	while(pos != NULL)
	{
		book_num.GetNextAssoc(pos, book_isbn, nums);
		//MessageBox(book_isbn);
		cnum.Format("%d", nums);
		//book = book + cnum;
		file.WriteString(book);
		//MessageBox(cnum);
		file.WriteString(" ");
		file.WriteString(cnum + "\n");
	
	}
	// TODO: Add extra validation here
	file.Close();
	
}



