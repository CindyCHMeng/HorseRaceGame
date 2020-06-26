// ResultView.cpp : 實作檔
//

#include "stdafx.h"
#include "Race.h"
#include "ResultView.h"
#include "GameSplitterWnd.h"
#include <string.h>


// CResultView

IMPLEMENT_DYNCREATE(CResultView, CFormView)

CResultView::CResultView()
	: CFormView(CResultView::IDD)
{

}

CResultView::~CResultView()
{
}

void CResultView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_START, m_StartButton);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_StopButton);
	DDX_Control(pDX, IDC_RANKTEXT1, m_RankText1);
	DDX_Control(pDX, IDC_RANKTEXT2, m_RankText2);
	DDX_Control(pDX, IDC_RANKTEXT3, m_RankText3);
	DDX_Control(pDX, IDC_RANKTEXT4, m_RankText4);
	DDX_Control(pDX, IDC_RANKTEXT5, m_RankText5);
	DDX_Control(pDX, IDC_RANKTEXT6, m_RankText6);
}

BEGIN_MESSAGE_MAP(CResultView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_START, &CResultView::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CResultView::OnBnClickedButtonStop)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CResultView 診斷

#ifdef _DEBUG
void CResultView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CResultView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CResultView 訊息處理常式

void CResultView::ShowResult(std::list<int> rank)
{
	int iNumber = 1;

	for (auto tempRank : rank)
	{
		TCHAR sNumber[5];
		wsprintf(sNumber, _T("%d"), iNumber);

		switch (tempRank)
		{
			case 1:
				m_RankText1.SetWindowTextW(sNumber);
				break;

			case 2 :
				m_RankText2.SetWindowTextW(sNumber);
				break;

			case 3:
				m_RankText3.SetWindowTextW(sNumber);
				break;

			case 4:
				m_RankText4.SetWindowTextW(sNumber);
				break;

			case 5:
				m_RankText5.SetWindowTextW(sNumber);
				break;

			case 6:
				m_RankText6.SetWindowTextW(sNumber);
				break;

			default:
				break;
		}

		iNumber++;
	}
}

void CResultView::InitialButton()
{
	m_StartButton.EnableWindow(1);
	m_StopButton.EnableWindow(0);
}

void CResultView::OnBnClickedButtonStart()
{
	m_StartButton.EnableWindow(0);
	m_StopButton.EnableWindow(1);

	if (GetParent()->IsKindOf(RUNTIME_CLASS(CGameSplitterWnd)))
	{
		CGameSplitterWnd * pGameSplitterWnd = (CGameSplitterWnd*)GetParent();
		pGameSplitterWnd->StartGame();
	}
}


void CResultView::OnBnClickedButtonStop()
{
	if (GetParent()->IsKindOf(RUNTIME_CLASS(CGameSplitterWnd)))
	{
		CGameSplitterWnd * pGameSplitterWnd = (CGameSplitterWnd*)GetParent();
		pGameSplitterWnd->StopGame();
	}

	InitialButton();
}


int CResultView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}


void CResultView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	InitialButton();
}
