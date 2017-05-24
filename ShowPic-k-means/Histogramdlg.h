#if !defined(AFX_HISTOGRAMDLG_H__BE147328_206A_49BD_9F56_880E0F75584D__INCLUDED_)
#define AFX_HISTOGRAMDLG_H__BE147328_206A_49BD_9F56_880E0F75584D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Histogramdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistogramdlg dialog

class CHistogramdlg : public CDialog
{
// Construction
public:
	CHistogramdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistogramdlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistogramdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistogramdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTOGRAMDLG_H__BE147328_206A_49BD_9F56_880E0F75584D__INCLUDED_)
