#pragma once

#ifndef _NEW_THREADCTRL_LIB_EXPORT_
#ifndef DLLEXPORT
#define DLLEXPORT    __declspec(dllimport)
#endif
#else
#ifndef DLLEXPORT
#define DLLEXPORT    __declspec(dllexport)
#endif
#endif

#include <afxmt.h>


const UINT WM_STATUSCHANGE = RegisterWindowMessage(_T("WM_STATUSCHANGE"));

class DLLEXPORT CHorses
{
protected:
	int m_MaxSpeed;
	int m_Distance;
	HWND m_Wnd;
	int m_Number;
	CWinThread * pThread;
	CEvent m_StartEvent;
	bool m_Running;
	//CCriticalSection m_CriticalSection;
	//CSingleLock m_RunningLock;

public:
	CHorses(int iID, HWND wnd);
	~CHorses();
//	void SetSpeed(int speed) { m_MaxSpeed = speed; }
//	void SetWnd(HWND wnd) { m_Wnd = wnd; }
//	void SetNumber(int num) { m_Number = num; }
//	void SetStartEvent(CEvent * startEvent) { m_StartEvent = startEvent; }
	void StopRunning() { m_Running = false; m_StartEvent.ResetEvent(); }
	void StartToRun() { m_Running = true; m_StartEvent.SetEvent(); }
	int GetDistance() const { return m_Distance; }
	int GetNumber() const { return m_Number; }

private:
	static UINT Run(LPVOID raceDistance);
	
	
};

