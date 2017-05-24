// ShowPicView.h : interface of the CShowPicView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWPICVIEW_H__EE33132B_8E65_476A_BB28_9B52D2DA3970__INCLUDED_)
#define AFX_SHOWPICVIEW_H__EE33132B_8E65_476A_BB28_9B52D2DA3970__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowPicView : public CView
{
protected: // create from serialization only
	CShowPicView();
	DECLARE_DYNCREATE(CShowPicView)

// Attributes
public:
	CShowPicDoc* GetDocument();


public:
	//成员变量
	CString BmpName;                               //保存图像文件文件名
	CString EntName;                               //保存图像文件扩展名
	CBitmap m_bitmap;                              //创建位图对象

	//成员函数
	void ShowBitmap(CDC* pDC,CString BmpName);    //用来显示指定位图bmp的函数




// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowPicView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowPicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowPicView)
	afx_msg void OnMenuitem32773();
	afx_msg void OnHistogram();
	afx_msg void OnShowHistogram();
	afx_msg void OnKMeansimagesegmentation();
	afx_msg void OnKmeans();
	afx_msg void OnKMeansImageSegmentation();
	afx_msg void OnColorToGray();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowPicView.cpp
inline CShowPicDoc* CShowPicView::GetDocument()
   { return (CShowPicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPICVIEW_H__EE33132B_8E65_476A_BB28_9B52D2DA3970__INCLUDED_)
