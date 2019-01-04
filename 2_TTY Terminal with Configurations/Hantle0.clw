; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSetPortDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Hantle0.h"
LastPage=0

ClassCount=7
Class1=CHantle0App
Class2=CHantle0Doc
Class3=CHantle0View
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_SET_PORT
Class5=CAboutDlg
Resource3=IDD_DIALOG1
Resource4=IDR_MAINFRAME
Class6=CSetPortDlg
Class7=CSetTerminalDlg
Resource5=IDD_SET_TERMINAL

[CLS:CHantle0App]
Type=0
HeaderFile=Hantle0.h
ImplementationFile=Hantle0.cpp
Filter=N
LastObject=CHantle0App
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CHantle0Doc]
Type=0
HeaderFile=Hantle0Doc.h
ImplementationFile=Hantle0Doc.cpp
Filter=N

[CLS:CHantle0View]
Type=0
HeaderFile=Hantle0View.h
ImplementationFile=Hantle0View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_SET_TERMINAL

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SET_PORT
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CAboutDlg]
Type=0
HeaderFile=Hantle0.cpp
ImplementationFile=Hantle0.cpp
Filter=D
LastObject=ID_PHONE_CONNECT

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_PHONE_CONNECT
Command15=ID_PHONE_DISCONNECT
Command16=ID_SET_PORT
Command17=ID_SET_TERMINAL
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_PHONE_CONNECT
Command10=ID_PHONE_DISCONNECT
CommandCount=10

[DLG:IDD_DIALOG1]
Type=1
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_SET_TERMINAL]
Type=1
Class=CSetTerminalDlg
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_TERMINAL_COMBO,combobox,1344339971
Control4=IDC_FONT_BUTTON,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_SENDLF_CHECK,button,1342373891
Control7=IDC_LOCALECHO_CHECK,button,1342242819
Control8=IDC_RECIEVELF_CHECK,button,1342242819
Control9=IDC_AUTOWRAP_CHECK,button,1342242819
Control10=IDOK,button,1342242817
Control11=IDCANCEL,button,1342242816

[DLG:IDD_SET_PORT]
Type=1
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=65535,button,1342177287
Control4=65535,static,1342308352
Control5=IDC_PORT_COMBO,combobox,1344340483
Control6=65535,static,1342177280
Control7=IDC_BAUD_COMBO,combobox,1344340483
Control8=65535,static,1342177280
Control9=IDC_DATABITS_COMBO,combobox,1344340483
Control10=65535,static,1342177280
Control11=IDC_PARITY_COMBO,combobox,1344340483
Control12=65535,static,1342177280
Control13=IDC_STOPBITS_COMBO,combobox,1344340483
Control14=65535,static,1342177280
Control15=IDC_DTRDSR_CHECK,button,1342242819
Control16=IDC_RTSCTS_CHECK,button,1342177283
Control17=IDC_XONXOFF_CHECK,button,1342177283
Class=CSetPortDlg

[CLS:CSetPortDlg]
Type=0
HeaderFile=SetPortDlg.h
ImplementationFile=SetPortDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[CLS:CSetTerminalDlg]
Type=0
HeaderFile=SetTerminalDlg.h
ImplementationFile=SetTerminalDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

