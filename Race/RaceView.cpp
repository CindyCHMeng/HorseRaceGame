
// RaceView.cpp : CRaceView 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "Race.h"
#endif

#include "RaceDoc.h"
#include "RaceView.h"
#include <map>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRaceView

IMPLEMENT_DYNCREATE(CRaceView, CView)

BEGIN_MESSAGE_MAP(CRaceView, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CRaceView 建構/解構

CRaceView::CRaceView()
{
	// TODO:  在此加入建構程式碼
	
}

CRaceView::~CRaceView()
{
}

BOOL CRaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CRaceView 描繪

void CRaceView::OnDraw(CDC* /*pDC*/)
{
	CRaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  在此加入原生資料的描繪程式碼
}


// CRaceView 列印

BOOL CRaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CRaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印前額外的初始設定
}

void CRaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印後的清除程式碼
}


// CRaceView 診斷

#ifdef _DEBUG
void CRaceView::AssertValid() const
{
	CView::AssertValid();
}

void CRaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRaceDoc* CRaceView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRaceDoc)));
	return (CRaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CRaceView 訊息處理常式

CRect CRaceView::GetRect(int number, int distance)
{
	CRect tempRect;

	tempRect.left = HORSE_INITPOS_X + distance;
	tempRect.right = tempRect.left + 50;
	tempRect.top = 7 + ((number - 1) * 60);
	tempRect.bottom = 57 + ((number - 1) * 60);

	return tempRect;
}


void CRaceView::ShowResult(int number, int distance)
{
	if (distance > RACEDISTANCE)
		distance = RACEDISTANCE;

	CRect tempRect = GetRect(number, distance);

	m_Horse[number - 1]->MoveWindow(tempRect);
	m_Horse[number - 1]->UpdateWindow();
}


int CRaceView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	for (int i = 0; i < TOTALHORSE; i++)
	{
		//std::shared_ptr <CButton> tempHorse(new CButton());
		m_Horse.push_back(new CMyButton);

		switch (i + 1)
		{
			case 1:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(1, 0), this, IDC_BUTTON_Horse1);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE1), IMAGE_ICON, 48, 48, 0));
				break;

			case 2:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(2, 0), this, IDC_BUTTON_Horse2);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE2), IMAGE_ICON, 48, 48, 0));
				break;

			case 3:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(3, 0), this, IDC_BUTTON_Horse3);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE3), IMAGE_ICON, 48, 48, 0));
				break;

			case 4:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(4, 0), this, IDC_BUTTON_Horse4);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE4), IMAGE_ICON, 48, 48, 0));
				break;

			case 5:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(5, 0), this, IDC_BUTTON_Horse5);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE5), IMAGE_ICON, 48, 48, 0));
				break;

			case 6:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(6, 0), this, IDC_BUTTON_Horse6);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE6), IMAGE_ICON, 48, 48, 0));
				break;

			default:
				break;
		}
	}

	return 0;
}


void CRaceView::OnDestroy()
{
	CView::OnDestroy();

	// TODO:  在此加入您的訊息處理常式程式碼
	for (size_t i = 0; i < m_Horse.size(); i++)
	{
		delete m_Horse.at(i);
	}
	m_Horse.clear();
}
