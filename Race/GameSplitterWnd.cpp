// GameSplitterWnd.cpp : 實作檔
//

#include "stdafx.h"
#include "Race.h"
#include "GameSplitterWnd.h"
#include "RaceView.h"
#include "ResultView.h"
#include <time.h>


// CGameSplitterWnd

IMPLEMENT_DYNAMIC(CGameSplitterWnd, CSplitterWnd)

CGameSplitterWnd::CGameSplitterWnd()
{
	srand((unsigned)time(NULL));
}

CGameSplitterWnd::~CGameSplitterWnd()
{
}


BEGIN_MESSAGE_MAP(CGameSplitterWnd, CSplitterWnd)
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_REGISTERED_MESSAGE(WM_STATUSCHANGE, UpdateRaceResult)
	ON_REGISTERED_MESSAGE(WM_ENDGAME, InitialButton)
END_MESSAGE_MAP()



// CGameSplitterWnd 訊息處理常式

LRESULT CGameSplitterWnd::UpdateRaceResult(WPARAM number, LPARAM distance)
{
	CWnd* pWnd0 = GetPane(0, 0);
	CWnd* pWnd1 = GetPane(1, 0);

	if (pWnd0->IsKindOf(RUNTIME_CLASS(CRaceView)))
	{
		CRaceView * pRaceView = (CRaceView*)pWnd0;
		pRaceView->ShowResult(number, distance);
	}

	if (pWnd1->IsKindOf(RUNTIME_CLASS(CResultView)))
	{
		CResultView * pResultView = (CResultView*)pWnd1;
		pResultView->ShowResult(m_RaceCtrl.GetHorseOrder(number, distance));
	}

	return 0;
}


LRESULT CGameSplitterWnd::InitialButton(WPARAM wParam, LPARAM lParam)
{
	CWnd* pWnd = GetPane(1, 0);
	if (pWnd->IsKindOf(RUNTIME_CLASS(CResultView)))
	{
		CResultView * pResultView = (CResultView*)pWnd;
		pResultView->InitialButton();
	}

	return 0;
}


void CGameSplitterWnd::OnMove(int x, int y)
{
//	CSplitterWnd::OnMove(x, y);

	// TODO:  在此加入您的訊息處理常式程式碼
}


void CGameSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	//CSplitterWnd::OnLButtonDown(nFlags, point);
}


int CGameSplitterWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CSplitterWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_RaceCtrl.SetWnd(GetSafeHwnd());

	return 0;
}
