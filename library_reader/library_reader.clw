; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Admin
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "library_reader.h"
LastPage=0

ClassCount=8
Class1=BORROW
Class2=FUN
Class3=CLibrary_readerApp
Class4=CAboutDlg
Class5=CLibrary_readerDlg
Class6=Return
Class7=SIGN_UP

ResourceCount=7
Resource1=IDD_DIALOG_FUNCTION
Resource2=IDD_DIALOG1
Resource3=IDD_LIBRARY_READER_DIALOG
Resource4=IDD_SIGN_DIALOG
Resource5=IDD_ABOUTBOX
Resource6=IDD_DIALOG_BORROW
Class8=Admin
Resource7=IDD_DIALOG2

[CLS:BORROW]
Type=0
BaseClass=CDialog
HeaderFile=BORROW.h
ImplementationFile=BORROW.cpp

[CLS:FUN]
Type=0
BaseClass=CDialog
HeaderFile=FUN.h
ImplementationFile=FUN.cpp
Filter=D
VirtualFilter=dWC

[CLS:CLibrary_readerApp]
Type=0
BaseClass=CWinApp
HeaderFile=library_reader.h
ImplementationFile=library_reader.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=library_readerDlg.cpp
ImplementationFile=library_readerDlg.cpp

[CLS:CLibrary_readerDlg]
Type=0
BaseClass=CDialog
HeaderFile=library_readerDlg.h
ImplementationFile=library_readerDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON1

[CLS:Return]
Type=0
BaseClass=CDialog
HeaderFile=Return.h
ImplementationFile=Return.cpp
LastObject=IDC_EDIT1
Filter=D
VirtualFilter=dWC

[CLS:SIGN_UP]
Type=0
BaseClass=CDialog
HeaderFile=SIGN_UP.h
ImplementationFile=SIGN_UP.cpp
LastObject=IDC_CANCEL

[DLG:IDD_DIALOG_BORROW]
Type=1
Class=BORROW
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_ISBN,edit,1350631552

[DLG:IDD_DIALOG_FUNCTION]
Type=1
Class=FUN
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_BUTTON1,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIBRARY_READER_DIALOG]
Type=1
Class=CLibrary_readerDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_USER,edit,1350631552
Control4=IDC_PASSWORD,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_SIGN_UP,button,1342242816
Control9=IDC_BUTTON1,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=Return
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552

[DLG:IDD_SIGN_DIALOG]
Type=1
Class=SIGN_UP
ControlCount=6
Control1=IDD_ACCOUNT,static,1342308352
Control2=IDC_EDIT_ACCOUNT,edit,1350631552
Control3=IDC_PASSWORD,static,1342308352
Control4=IDC_EDIT_PASSWORD,edit,1350631552
Control5=IDC_OK,button,1342242816
Control6=IDC_CANCEL,button,1342242816

[DLG:IDD_DIALOG2]
Type=1
Class=Admin
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_isbn,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_num,edit,1350631552

[CLS:Admin]
Type=0
HeaderFile=Admin.h
ImplementationFile=Admin.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON2
VirtualFilter=dWC

