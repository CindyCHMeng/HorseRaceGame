#pragma once
#include "RaceCtrl.h"


// CGameSplitterWnd

class CGameSplitterWnd : public CSplitterWnd
{
	DECLARE_DYNAMIC(CGameSplitterWnd)

protected:
	CRaceCtrl m_RaceCtrl;

public:
	CGameSplitterWnd();
	virtual ~CGameSplitterWnd();	
	void StartGame() { m_RaceCtrl.Start(); }
	void StopGame() { m_RaceCtrl.Stop(); }

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT UpdateRaceResult(WPARAM number, LPARAM distance);
	afx_msg LRESULT InitialButton(WPARAM wParam, LPARAM lParam);
};


