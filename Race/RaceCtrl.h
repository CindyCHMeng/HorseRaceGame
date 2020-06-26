#pragma once
#include "Horses.h"
#include <list>
#include <memory>
#include <string>
#include <vector>

#define RACEDISTANCE 800
#define TOTALHORSE 6

const UINT WM_ENDGAME = RegisterWindowMessage(_T("WM_ENDGAME"));

class CRaceCtrl
{
protected:
	HWND m_Wnd;
	std::list< std::shared_ptr<CHorses> > m_Horse;
	std::list<int> m_Order;
	int m_DistanceByNumber[TOTALHORSE];
	std::list<std::shared_ptr<CHorses>> m_EndGameHorse;
	CCriticalSection m_CriticalSection;
	CSingleLock m_RunningLock;

public:
	CRaceCtrl();
	CRaceCtrl(HWND wnd);
	~CRaceCtrl();
	void Start();
	void Stop();
	void SetWnd(HWND wnd);
	int GetRaceDis() const { return RACEDISTANCE; }	
	int* GetHorseDis() { return m_DistanceByNumber; }
	std::list<int> GetHorseOrder();
	std::list<int> GetHorseOrder(int number, int distance);

protected:
	void EndGame();
	void InitHorse();
	
};

