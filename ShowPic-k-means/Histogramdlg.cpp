// Histogramdlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowPic.h"
#include "Histogramdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistogramdlg dialog


CHistogramdlg::CHistogramdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistogramdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistogramdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHistogramdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistogramdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistogramdlg, CDialog)
	//{{AFX_MSG_MAP(CHistogramdlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistogramdlg message handlers
