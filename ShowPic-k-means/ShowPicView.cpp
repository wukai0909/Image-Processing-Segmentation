// ShowPicView.cpp : implementation of the CShowPicView class
//

#include "stdafx.h"
#include "ShowPic.h"

#include "ShowPicDoc.h"
#include "ShowPicView.h"

#include "dibapi.h"

#include "Histogramdlg.h"


#include <math.h>
#include <direct.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern long intWidth,intHeight;
extern unsigned char Data[610][800];
extern unsigned char OriData[610][800];
char Flag='0';
unsigned char NewData[610][800];
float a1[256],c1[256],f1[256];
extern BYTE pic[3000][3000][3];

/////////////////////////////////////////////////////////////////////////////
// CShowPicView

IMPLEMENT_DYNCREATE(CShowPicView, CView)

BEGIN_MESSAGE_MAP(CShowPicView, CView)
	//{{AFX_MSG_MAP(CShowPicView)
	ON_COMMAND(ID_MENUITEM32773, OnMenuitem32773)
	ON_COMMAND(ID_K_Means_image_segmentation, OnKMeansimagesegmentation)
	ON_COMMAND(ID_KMEANS, OnKmeans)
	ON_COMMAND(ID_KMeans_ImageSegmentation, OnKMeansImageSegmentation)
	ON_COMMAND(ID_COLOR_TO_GRAY, OnColorToGray)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowPicView construction/destruction


// CShowPicView construction/destruction

CShowPicView::CShowPicView()
{
	// TODO: add construction code here

}

CShowPicView::~CShowPicView()
{
}

BOOL CShowPicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowPicView drawing


/////////////////////////////////////////////////////////////////////////////
// CShowPicView printing

BOOL CShowPicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowPicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowPicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowPicView diagnostics

#ifdef _DEBUG
void CShowPicView::AssertValid() const
{
	CView::AssertValid();
}

void CShowPicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowPicDoc* CShowPicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowPicDoc)));
	return (CShowPicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowPicView message handlers




//在OnDraw函数中调用ShowBitmap()实现图片的显示功能
void CShowPicView::OnDraw(CDC* pDC)
{
	CShowPicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	 int i,j;
    // 字符串
	CString str;
	///////////////////////画原始图像
	if(pDoc->flag==1)//24位彩色图
		for(int y = 0; y < intHeight-1; y++)
	    {for(int x = 0; x < intWidth-1; x++)
			{
		      pDC->SetPixel(x,y,RGB(pDoc->pic[y][x][0],pDoc->pic[y][x][1],pDoc->pic[y][x][2]));
			}
	    }
	if(pDoc->flag==2)//灰度图由Data[i][j]备份过的OriData[i][j]来显示源像数

		for(j = 0; j < intWidth; j++)
	    {
			for(i = 0; i < intHeight; i++)
			{
		      pDC->SetPixel(j,i,RGB(OriData[i][j],OriData[i][j],OriData[i][j]));
			}
	    }

	if(Flag=='B')
		{
		for(i = 0; i < intHeight; i++)
		{
			for(j = 0; j < intWidth; j++)
				{
				j=j;
			     pDC->SetPixel(j+600,i,RGB(256-Data[i][j],256-Data[i][j],256-Data[i][j]));
				}
		 }
	}

}

void CShowPicView::OnColorToGray() 
{
	CShowPicDoc* pDoc = GetDocument();
	CDC* pDC=GetDC();
	int i,j;

	if(pDoc->flag==1)	//24位BMP
	{		 
		for(int y=0; y<intHeight; y++)
		{
			for(int x=0; x<intWidth; x++)
			{  
			Data[y][x] = (unsigned char)((pDoc->pic[y][x][0])* 0.30+(pDoc->pic[y][x][1])* 0.59 +(pDoc->pic[y][x][2])* 0.11);			 
			}
		}

		for(j = 0; j < intWidth; j++)
		{
			for(i = 0; i <intHeight ; i++)
			{
			//	pDC->SetPixel(j,i+intHeight+30,RGB(Data[i][j],Data[i][j],Data[i][j]));
				pDC->SetPixel(j,i,RGB(Data[i][j],Data[i][j],Data[i][j]));
			}
		}	

		for(i = 0; i < intWidth; i++)
		{
			for(j = 0; j < intHeight; j++)
				{
					OriData[j][i] =Data[j][i];
				}
		}

	}
	
}

void CShowPicView::OnMenuitem32773() 
{
	// TODO: Add your command handler code here

   	Flag='B';
     Invalidate();

}

struct cluster
{
  int r;
  int g;
  int b;
  int num;
  int index;
  double total_r;
  double total_g;
  double total_b;
};

struct clustertemp
{
  int r;
  int g;
  int b;
};


void CShowPicView::OnKmeans() 
{
	CShowPicDoc* pDoc = GetDocument();
	CDC* pDC=GetDC();
	srand((unsigned int)time(NULL));
	int center1=rand()%256,center2=rand()%256, distance1 = 0,distance2 =0;
	int temp_center1 =0,temp_center2=0;
	int i=0,j=0;
	bool convergence = 1;
	do{
		double center1_count = 0,center2_count = 0, count1 = 0, count2 = 0;
		for(j = 0; j < intHeight; j++)//将图像中各像素值及特征读取出来
		{
			for(i = 0; i < intWidth; i++)
			{
				distance1 = abs(center1-Data[j][i]);
				distance2 = abs(center2-Data[j][i]);
				if(distance1<distance2) {
					center1_count+=Data[j][i];
					count1++;
				}
				else{
					center2_count+=Data[j][i];
					count2++;
				}
			}
		}
		temp_center1 = int(center1_count/count1);
		temp_center2 = int(center2_count/count2);
		if(abs(temp_center1-center1)<0.1&&abs(temp_center2-center2)<0.1)
			convergence = 0;
		else
		{
			center1 = temp_center1;
			center2 = temp_center2;
		}

	}while(convergence);

	for(j = 0; j < intHeight; j++)//将图像中各像素值及特征读取出来
		for(i = 0; i < intWidth; i++)
			abs(center1-Data[j][i]) > abs(center2-Data[j][i]) ? pDC->SetPixel(i+intWidth,j,RGB(255,255,255)) : pDC->SetPixel(i+intWidth,j,RGB(0,0,0));

	delete pDoc;
	ReleaseDC(pDC);
	pDoc = NULL;
	pDC  = NULL;
}

void CShowPicView::OnKMeansimagesegmentation() 
{
	CShowPicDoc* pDoc = GetDocument();
	CDC* pDC=GetDC();
	int R_center1=5,R_center2=100;
	int G_center1=5,G_center2=100;
	int B_center1=5,B_center2=100;	
	int R_temp_center1 =0,R_temp_center2=0;
	int G_temp_center1 =0,G_temp_center2=0;
	int B_temp_center1 =0,B_temp_center2=0;
	int i=0,j=0;
	int	distance1 = 0,distance2 =0;	
	bool convergence = 1;
	do{
		double R_center1_count = 0, R_center2_count = 0, R_count1 = 0, R_count2 = 0;
		double G_center1_count = 0, G_center2_count = 0, G_count1 = 0, G_count2 = 0;
		double B_center1_count = 0, B_center2_count = 0, B_count1 = 0, B_count2 = 0;
		//pDC->SetPixel(x,y,RGB(pDoc->pic[y][x][0],pDoc->pic[y][x][1],pDoc->pic[y][x][2]));
		for(j = 0; j < intHeight; j++)//将图像中各像素值及特征读取出来
		{
			for(i = 0; i < intWidth; i++)
			{
				distance1 = abs(R_center1-pDoc->pic[j][i][0]); distance2 = abs(R_center2-pDoc->pic[j][i][0]);
				if(distance1<distance2) {
					R_center1_count+=pDoc->pic[j][i][0];   R_count1++;
				}
				else{
					R_center2_count+=pDoc->pic[j][i][0];   R_count2++;
				}

				distance1 = abs(G_center1-pDoc->pic[j][i][1]); distance2 = abs(G_center2-pDoc->pic[j][i][1]);
				if(distance1<distance2) {
					G_center1_count+=pDoc->pic[j][i][1];   G_count1++;
				}
				else{
					G_center2_count+=pDoc->pic[j][i][1];   G_count2++;
				}

				distance1 = abs(B_center1-pDoc->pic[j][i][2]); distance2 = abs(B_center2-pDoc->pic[j][i][2]);
				if(distance1<distance2) {
					B_center1_count+=pDoc->pic[j][i][2];   B_count1++;
				}
				else{
					B_center2_count+=pDoc->pic[j][i][2];   B_count2++;
				}
			}
		}
		R_temp_center1 = int(R_center1_count/R_count1);		R_temp_center2 = int(R_center2_count/R_count2);
		G_temp_center1 = int(G_center1_count/G_count1);		G_temp_center2 = int(G_center2_count/G_count2);
		B_temp_center1 = int(B_center1_count/B_count1);		B_temp_center2 = int(B_center2_count/B_count2);
		if(	  abs(R_temp_center1-R_center1)<0.1&&abs(R_temp_center2-R_center2)<0.1
			&&abs(G_temp_center1-G_center1)<0.1&&abs(G_temp_center2-G_center2)<0.1
			&&abs(B_temp_center1-B_center1)<0.1&&abs(B_temp_center2-B_center2)<0.1)
			convergence = 0;
		else
		{
			R_center1 = R_temp_center1;			R_center2 = R_temp_center2;
			G_center1 = G_temp_center1;			G_center2 = G_temp_center2;
			B_center1 = B_temp_center1;			B_center2 = B_temp_center2;
		}

	}while(convergence);
	int temp1=0,temp2=0,temp3=0;
	for(j = 0; j < intHeight; j++)//将图像中各像素值及特征读取出来
		for(i = 0; i < intWidth; i++)
		{
			distance1 = abs(R_center1-pDoc->pic[j][i][0])+abs(G_center1-pDoc->pic[j][i][1])+abs(B_center1-pDoc->pic[j][i][2]); 
			distance2 = abs(R_center2-pDoc->pic[j][i][0])+abs(G_center2-pDoc->pic[j][i][1])+abs(B_center2-pDoc->pic[j][i][2]);
			distance1 > distance2 ? pDC->SetPixel(i+2*intWidth,j,RGB(255,255,255)) : pDC->SetPixel(i+2*intWidth,j,RGB(0,0,0));
			abs(R_center1-pDoc->pic[j][i][0])>abs(R_center2-pDoc->pic[j][i][0]) ? temp1=255 : temp1=0 ;
			abs(G_center1-pDoc->pic[j][i][1])>abs(G_center2-pDoc->pic[j][i][1]) ? temp2=255 : temp2=0 ;
			abs(B_center1-pDoc->pic[j][i][2])>abs(B_center2-pDoc->pic[j][i][2]) ? temp3=255 : temp3=0 ;
			pDC->SetPixel(i+intWidth,j,RGB(temp1,temp2,temp3));
		}

//	delete pDoc;
//	ReleaseDC(pDC);
//	pDoc = NULL;
//	pDC  = NULL;
}


void CShowPicView::OnKMeansImageSegmentation() 
{
	CShowPicDoc* pDoc = GetDocument();
	CDC* pDC=GetDC();
	srand((unsigned int)time(NULL));

	int R_center1=rand()%256,R_center2=rand()%256;
	int G_center1=rand()%256,G_center2=rand()%256;
	int B_center1=rand()%256,B_center2=rand()%256;	
	int R_temp_center1 =0,R_temp_center2=0;
	int G_temp_center1 =0,G_temp_center2=0;
	int B_temp_center1 =0,B_temp_center2=0;
	int i=0,j=0;
	double	distance1 = 0,distance2 =0;	
	bool convergence = 1;
	do{
		double R_center1_count = 0, R_center2_count = 0, R_count1 = 0, R_count2 = 0;
		double G_center1_count = 0, G_center2_count = 0, G_count1 = 0, G_count2 = 0;
		double B_center1_count = 0, B_center2_count = 0, B_count1 = 0, B_count2 = 0;
		//pDC->SetPixel(x,y,RGB(pDoc->pic[y][x][0],pDoc->pic[y][x][1],pDoc->pic[y][x][2]));
		for(j = 0; j < intHeight; j++)//将图像中各像素值及特征读取出来
		{
			for(i = 0; i < intWidth; i++)
			{
				distance1 = sqrt( pow((R_center1-pDoc->pic[j][i][0]),2)+pow((G_center1-pDoc->pic[j][i][1]),2)+pow((B_center1-pDoc->pic[j][i][2]),2) ); 
				distance2 = sqrt( pow((R_center2-pDoc->pic[j][i][0]),2)+pow((G_center2-pDoc->pic[j][i][1]),2)+pow((B_center2-pDoc->pic[j][i][2]),2) );
				if(distance1<distance2) {
					R_center1_count+=pDoc->pic[j][i][0];   R_count1++;
					G_center1_count+=pDoc->pic[j][i][1];   G_count1++;
					B_center1_count+=pDoc->pic[j][i][2];   B_count1++;
				}
				else{
					R_center2_count+=pDoc->pic[j][i][0];   R_count2++;
					G_center2_count+=pDoc->pic[j][i][1];   G_count2++;
					B_center2_count+=pDoc->pic[j][i][2];   B_count2++;
				}
			}
		}
		R_temp_center1 = int(R_center1_count/R_count1);		R_temp_center2 = int(R_center2_count/R_count2);
		G_temp_center1 = int(G_center1_count/G_count1);		G_temp_center2 = int(G_center2_count/G_count2);
		B_temp_center1 = int(B_center1_count/B_count1);		B_temp_center2 = int(B_center2_count/B_count2);
		if(	  abs(R_temp_center1-R_center1)<0.1&&abs(R_temp_center2-R_center2)<0.1
			&&abs(G_temp_center1-G_center1)<0.1&&abs(G_temp_center2-G_center2)<0.1
			&&abs(B_temp_center1-B_center1)<0.1&&abs(B_temp_center2-B_center2)<0.1)
			convergence = 0;
		else
		{
			R_center1 = R_temp_center1;			R_center2 = R_temp_center2;
			G_center1 = G_temp_center1;			G_center2 = G_temp_center2;
			B_center1 = B_temp_center1;			B_center2 = B_temp_center2;
		}

	}while(convergence);

	for(j = 0; j < intHeight; j++)//将图像中各像素值及特征读取出来
		for(i = 0; i < intWidth; i++)
		{
			distance1 = sqrt( pow((R_center1-pDoc->pic[j][i][0]),2)+pow((G_center1-pDoc->pic[j][i][1]),2)+pow((B_center1-pDoc->pic[j][i][2]),2) ); 
			distance2 = sqrt( pow((R_center2-pDoc->pic[j][i][0]),2)+pow((G_center2-pDoc->pic[j][i][1]),2)+pow((B_center2-pDoc->pic[j][i][2]),2) );
			distance1 > distance2 ? pDC->SetPixel(i+intWidth,j,RGB(255,255,255)) : pDC->SetPixel(i+intWidth,j,RGB(0,0,0));
		}
}

