#include "stdafx.h"
#include "RaceCtrl.h"
#include <map>


CRaceCtrl::CRaceCtrl()
	: m_RunningLock(&m_CriticalSection)
{
	
}

CRaceCtrl::CRaceCtrl(HWND wnd)
	: m_Wnd(wnd), m_RunningLock(&m_CriticalSection)
{
	/*
	for (int i = 0; i < TOTALHORSE; i++)
	{
		std::shared_ptr <CHorses> tempHorse;
//		tempHorse->SetWnd(wnd);
		
		m_Horse.push_back(tempHorse);
		m_Order.push_back(i + 1);
	}
	*/
}


CRaceCtrl::~CRaceCtrl()
{
}


void CRaceCtrl::Start()
{
	InitHorse();

	// Run
	for (std::shared_ptr<CHorses> tempHorse : m_Horse)
	{
		tempHorse->StartToRun();
	}
	
//	m_StartEvent.SetEvent();
}


void CRaceCtrl::Stop()
{
	//m_RunningLock.Lock();
	for (std::shared_ptr<CHorses> tempHorse : m_Horse)
	{
		tempHorse->StopRunning();
		TRACE("CHorses(%d) Stop\n", tempHorse->GetNumber());
	}
	//m_RunningLock.Unlock();

	//m_Horse.clear();
}


void CRaceCtrl::SetWnd(HWND wnd)
{
	m_Wnd = wnd;
}


void CRaceCtrl::InitHorse()
{
	m_Horse.clear();
	m_EndGameHorse.clear();
	
	for (int i = 0; i < TOTALHORSE; i++)
	{
		std::shared_ptr <CHorses> tempHorse(new CHorses(i + 1, m_Wnd));
		m_Horse.push_back(tempHorse);
		m_Order.push_back(i + 1);
		m_DistanceByNumber[i] = 0;
	}
}


std::list<int> CRaceCtrl::GetHorseOrder(int number, int distance)
{
	std::multimap<int, int> tempHorseList;

	m_Order.clear();

	if (RACEDISTANCE <= distance)
	{
		m_DistanceByNumber[number - 1] = RACEDISTANCE;

		std::list< std::shared_ptr<CHorses> >::iterator Iter = m_Horse.begin();
		while (Iter != m_Horse.end())
		{
			int tempNum = (*Iter)->GetNumber();

			if (tempNum == number)
			{
				(*Iter)->StopRunning();
				m_EndGameHorse.push_back(*Iter);

				Iter = m_Horse.erase(Iter);
				break;
			}
			Iter++;
		}
	}
	else
	{
		m_DistanceByNumber[number - 1] = distance;
	}
	
	for (int i = 0; i < TOTALHORSE; i++)
	{
		int tempDis = m_DistanceByNumber[i];

		if (tempDis != RACEDISTANCE)
		{
			tempHorseList.insert(std::make_pair(tempDis, (i + 1)));
		}
	}
	
	for (std::shared_ptr<CHorses> tempHorse : m_EndGameHorse)
	{
		m_Order.push_back(tempHorse->GetNumber());
	}

	std::multimap<int, int>::const_reverse_iterator iter = tempHorseList.rbegin();
	while (iter != tempHorseList.rend())
	{
		//TRACE("%d-%d\n", iter->first, iter->second);
		m_Order.push_back(iter->second);
		iter++;
	}

	if (m_EndGameHorse.size() == TOTALHORSE)
		EndGame();

	return m_Order;
}


std::list<int> CRaceCtrl::GetHorseOrder()
{
	std::multimap<int, int> tempHorseList;

	m_Order.clear();

	std::list< std::shared_ptr<CHorses> >::iterator Iter = m_Horse.begin();
	while (Iter != m_Horse.end())
	{
		int tempDis = (*Iter)->GetDistance();
		int tempNum = (*Iter)->GetNumber();

		if (tempDis >= RACEDISTANCE)
		{
			(*Iter)->StopRunning();
			m_EndGameHorse.push_back(*Iter);
			m_DistanceByNumber[tempNum - 1] = RACEDISTANCE;

			Iter = m_Horse.erase(Iter);
		}
		else
		{
			tempHorseList.insert(std::make_pair(tempDis, tempNum));
			m_DistanceByNumber[tempNum - 1] = tempDis;

			Iter++;
		}
	}

	for (std::shared_ptr<CHorses> tempHorse : m_EndGameHorse)
	{
		m_Order.push_back(tempHorse->GetNumber());
	}

	std::multimap<int, int>::const_reverse_iterator iter = tempHorseList.rbegin();
	while (iter != tempHorseList.rend())
	{
		//TRACE("%d-%d\n", iter->first, iter->second);
		m_Order.push_back(iter->second);
		iter++;
	}

	if (m_EndGameHorse.size() == TOTALHORSE)
		EndGame();

	return m_Order;
}


void CRaceCtrl::EndGame()
{
	::PostMessage(m_Wnd, WM_ENDGAME, 0, 0);
}