
// MainFrm.h : CMainFrame ���O������
//

#pragma once
#include "GameSplitterWnd.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �ȱq�ǦC�ƫإ�
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// �ݩ�
protected:
	CGameSplitterWnd m_wndSplitter;
public:

// �@�~
public:

// �мg
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �{���X��@
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ����C���O������
//	CToolBar          m_wndToolBar;
//	CStatusBar        m_wndStatusBar;

// ���ͪ��T�������禡
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


