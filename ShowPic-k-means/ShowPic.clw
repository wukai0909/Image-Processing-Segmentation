; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShowPicView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShowPic.h"
LastPage=0

ClassCount=6
Class1=CShowPicApp
Class2=CShowPicDoc
Class3=CShowPicView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CHistogramdlg
Resource3=IDD_DIALOG1

[CLS:CShowPicApp]
Type=0
HeaderFile=ShowPic.h
ImplementationFile=ShowPic.cpp
Filter=N

[CLS:CShowPicDoc]
Type=0
HeaderFile=ShowPicDoc.h
ImplementationFile=ShowPicDoc.cpp
Filter=N

[CLS:CShowPicView]
Type=0
HeaderFile=ShowPicView.h
ImplementationFile=ShowPicView.cpp
Filter=C
LastObject=ID_MENUITEM32773
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_COLOR_TO_GRAY




[CLS:CAboutDlg]
Type=0
HeaderFile=ShowPic.cpp
ImplementationFile=ShowPic.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
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
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_MENUITEM32773
Command18=ID_COLOR_TO_GRAY
Command19=ID_KMEANS
Command20=ID_KMeans_ImageSegmentation
Command21=ID_K_Means_image_segmentation
CommandCount=21

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
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CHistogramdlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177287

[CLS:CHistogramdlg]
Type=0
HeaderFile=Histogramdlg.h
ImplementationFile=Histogramdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHistogramdlg

