// library_readerDlg.cpp : implementation file
//
#include "stdafx.h"
#include "library_reader.h"
#include "library_readerDlg.h"
#include "FUN.h"
#include "Admin.h"
#include <string>
#include <sstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//一旦要借书，就建立映射，有一个built变量，去使不重复建立映射

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	//template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE);
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibrary_readerDlg dialog

CLibrary_readerDlg::CLibrary_readerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLibrary_readerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLibrary_readerDlg)
	m_password = _T("");
	m_user = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//分割线 建立用户到密码的映射
	CStdioFile file;
	file.Open("account.dat", CFile::modeRead);
	
	CString line;
	while(file.ReadString(line)) 
	{
	
		CString acc, pass;
		int index = line.Find(' ');
		acc = line.Mid(0, index);
		pass = line.Mid(index + 1, line.GetLength() - index - 1);
		
		acc_pass.SetAt(acc, pass);
	}	
	built = true;
	file.Close();
}

void CLibrary_readerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLibrary_readerDlg)
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 30);
	DDX_Text(pDX, IDC_USER, m_user);
	DDV_MaxChars(pDX, m_user, 30);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLibrary_readerDlg, CDialog)
	//{{AFX_MSG_MAP(CLibrary_readerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SIGN_UP, OnSignUp)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibrary_readerDlg message handlers

BOOL CLibrary_readerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLibrary_readerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLibrary_readerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLibrary_readerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CLibrary_readerDlg::Build()
{

}


void CLibrary_readerDlg::OnOK() 
{
	UpdateData();
	CString user, password;
	user.Format(m_user);
	password.Format(m_password);
	//Build();   //ok函数一定要在前面 
	FUN fun;
	
	//Lookup()函数功能有点强大
	//?通过key找到value, 赋给temp,检查temp == password
	//如果不是这样，那么key输入一个错误的就登陆不了。;
	//	MessageBox("no");
	//FUN *Fun = new FUN();
//	MessageBox(user);
	//MessageBox(password);
	CString temp;
	
		if(acc_pass.Lookup(user, temp))
	{
		fun.account = user;
		fun.DoModal();
	}
	else 
	{
		MessageBox("密码错误或者没有这个账号");
	}	
	
	
	//if(password == "123" && user == "123")
	//{
//		dig.DoModal();
	
//	}
	CDialog::OnOK();   //这里不会响应
}




void CLibrary_readerDlg::OnSignUp() 
{
	CDialog::OnOK();
	SIGN_UP sign;
	sign.DoModal();
	// TODO: Add your control notification handler code here
	
}

void CLibrary_readerDlg::OnButtonSign() 
{
	CDialog::OnOK();
	// TODO: Add your control notification handler code here
	Build();
//	CDialog::OnOK();   //ok函数一定要在前面
	FUN dig;
	CString user, password;
	user.Format(m_user);
	//MessageBox(user);
	password.Format(m_password);
	CString temp;

	//Lookup()函数功能有点强大
	//?通过key找到value, 赋给temp,检查temp == password
	//如果不是这样，那么key输入一个错误的就登陆不了。;
	//	MessageBox("no");
	
	
	if(acc_pass.Lookup(user, temp))
	{
		dig.account = user;
		dig.DoModal();
	}
	else 
	{
		MessageBox("密码错误");
	}
	//if(password == "123" && user == "123")
	//{
//		dig.DoModal();
	
//	}
	//CDialog::OnOK();   这里不会响应
	
}

void CLibrary_readerDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	Admin admin;
	if(m_user == "admin" && m_password == "admin")
	{
		admin.DoModal();
		return ;
	
	}
	
}
