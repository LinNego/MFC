// BORROW.cpp : implementation file
//

#include "stdafx.h"
#include "library_reader.h"
#include "BORROW.h"
#include <afx.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BORROW dialog


BORROW::BORROW(CWnd* pParent /*=NULL*/)
	: CDialog(BORROW::IDD, pParent)
{
	//{{AFX_DATA_INIT(BORROW)
	m_isbn = _T("");
	//}}AFX_DATA_INIT
	//分割线 这里建立一个映射书本到数量的映射
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
	}
}


void BORROW::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BORROW)
	DDX_Text(pDX, IDC_EDIT_ISBN, m_isbn);
	DDV_MaxChars(pDX, m_isbn, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BORROW, CDialog)
	//{{AFX_MSG_MAP(BORROW)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BORROW message handlers
void BORROW::OnOK() 
{
	CDialog::OnOK(); //为什么一定要放在前面
	  //建立映射关于书本isbn到书本的数量的
	CString isbn;
//	MessageBox(m_isbn);
	isbn.Format(m_isbn);
//	MessageBox(isbn);
	int temp;
	if(book_num.Lookup(isbn, temp) && temp != 0) 
	{
		book_num[isbn] -= 1;
		CStdioFile file;
	//	file.Open(")，应该传回给上一个对话框，根据参数是否重新建立文件。
		Build();
		MessageBox("借书成功");
	}
	else if(temp == 0)
	{
		MessageBox("该书可借数为0");
	
	}
	else 
	{
		MessageBox("该书不存在");
	
	}
}

void BORROW::Build()  //重新建立文件，这里建立书本isbn和书本的数量的文件
{	
	CStdioFile file;
	file.Open("book.dat", CFile::modeCreate|CFile::modeWrite);
	CString book, cnum;
	int num;
	POSITION pos = book_num.GetStartPosition();
	while(pos != NULL)
	{
		book_num.GetNextAssoc(pos, book, num);
		cnum.Format("%d", num);
		//book = book + cnum;
		file.WriteString(book);
		file.WriteString(" ");
		file.WriteString(cnum + "\n");
	}
	file.Close();
	CMap<CString, LPCTSTR, CString, LPCTSTR> acc_isbn;
	file.Open("account_isbn.dat", CFile::modeRead);
	CString line;
	while(file.ReadString(line))
	{
		CString acc, isbn;
		int index = line.Find(' ');
		acc = line.Mid(0, index);
		isbn = line.Mid(index + 1, line.GetLength() - index - 1);
		acc_isbn.SetAt(acc, isbn);
	
	}
	file.Close();
	acc_isbn[account] = m_isbn;
	file.Open("account_isbn.dat", CFile::modeCreate|CFile::modeWrite);
	pos = acc_isbn.GetStartPosition();
	CString user, isbns;
	while(pos != NULL)
	{
		acc_isbn.GetNextAssoc(pos, user, isbns);
		file.WriteString(user);
		file.WriteString(" ");
		file.WriteString(isbns + "\n");

	
	}
	file.Close();
	return ;
}

