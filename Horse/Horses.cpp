#include "stdafx.h"
#include "Horses.h"


CHorses::CHorses(int iID, HWND wnd)
	: m_Distance(0), m_Number(iID), m_Running(true), m_Wnd(wnd)
{
	m_StartEvent.ResetEvent();
	m_MaxSpeed = (int)(16 * ((double)rand() / (RAND_MAX + 1.0)) + 20);
	pThread = AfxBeginThread(Run, this);
}


CHorses::~CHorses()
{
}


UINT CHorses::Run(LPVOID tempHorse)
{
	CHorses *pHorse = (CHorses *)tempHorse;
	TRACE("CHorses(%d) - Start\n", pHorse->m_Number);
	Sleep(1);
	srand((unsigned)time(NULL));
	WaitForSingleObject(pHorse->m_StartEvent.m_hObject, INFINITE);

	TRACE("CHorses(%d) - Run\n", pHorse->m_Number);

	while (pHorse->m_Running)
	{		
//		int iRun = (int)((pHorse->m_MaxSpeed + 1) * ((double)rand() / (RAND_MAX + 1.0)) + 0);
		int iRun = rand() % pHorse->m_MaxSpeed;
		pHorse->m_Distance += iRun;
		::PostMessage(pHorse->m_Wnd, WM_STATUSCHANGE, pHorse->m_Number, pHorse->m_Distance);
		//::SendMessage(pHorse->m_Wnd, WM_STATUSCHANGE, pHorse->m_Number, pHorse->m_Distance);
		TRACE("CHorses(%d) Run=%d  %d    %d\n", pHorse->m_Number, iRun, pHorse->m_Distance, pHorse->m_Running);
		
		Sleep(200);
	}

	TRACE("CHorses(%d) End\n", pHorse->m_Number);
	return 0;
}