
// MainFrm.cpp : CMainFrame ���O����@
//

#include "stdafx.h"
#include "Race.h"

#include "MainFrm.h"
#include "Horses.h"
#include "RaceView.h"
#include "ResultView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���A�C���ܾ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame �غc/�Ѻc

CMainFrame::CMainFrame()
{
	// TODO:  �b���[�J������l�Ƶ{���X

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	/*
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("�L�k�إߤu��C\n");
		return -1;      // �L�k�إ�
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("�L�k�إߪ��A�C\n");
		return -1;      // �L�k�إ�
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	/
	// TODO:  �p�G�z���n�i�H�T�w�u��C�A�ЧR���o�T��
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	*/
	SetMenu(NULL);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER;
	cs.cx = 900;
	cs.cy = 680;

	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;

	return TRUE;
}

// CMainFrame �E�_

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �T���B�z�`��


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	m_wndSplitter.CreateStatic(this, 2, 1);

	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CRaceView), CSize(800, 370), pContext);
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(CResultView), CSize(800, 80), pContext);

//	CRect rect;
//	GetClientRect(&rect);
//	m_wndSplitter.SetRowInfo(0, rect.Height() * 3 / 7, 10);

	return TRUE;
}
