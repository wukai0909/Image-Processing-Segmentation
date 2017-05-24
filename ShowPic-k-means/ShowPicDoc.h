// ShowPicDoc.h : interface of the CShowPicDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWPICDOC_H__D8B4A037_B754_451C_9345_713E3809E378__INCLUDED_)
#define AFX_SHOWPICDOC_H__D8B4A037_B754_451C_9345_713E3809E378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DIBAPI.H"
// DIB¾ä±ú
//DECLARE_HANDLE(HDIB);

class CShowPicDoc : public CDocument
{
protected: // create from serialization only
	CShowPicDoc();
	DECLARE_DYNCREATE(CShowPicDoc)

// Attributes
public:
	HDIB GetHDIB() const 
	{ return hDIB; }

// Operations
public:
	HANDLE m_hDIB;
	char bfType[2];




	BYTE pic[3000][3000][3];
	BYTE propic[3000][3000][3];

	BYTE temppic[3000][3000][3];


	int flag;
	struct bf_head
	{
		long int bfSize;
		long bfReserved;
		long bfOffBits;
	}bf_h;
	struct bi_head
	{
		long biSize;
		long biWidth;
		long biHeight;
		short int biPlanes;
		short int biBitCount;
		long biCompression;
		long biSizeImage;
		long biXPelsPerMeter;
		long biYPelsPerMeter;
		long biClrUsed;
		long biClrImportant;
	}bi_h;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowPicDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowPicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HDIB m_hDIBOri;
	HDIB hDIB;
//	HDIB m_hDIB;
	CPalette* m_palDIB;
	CSize m_sizeDoc;

// Generated message map functions
protected:
	//{{AFX_MSG(CShowPicDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPICDOC_H__D8B4A037_B754_451C_9345_713E3809E378__INCLUDED_)
