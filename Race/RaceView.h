
// RaceView.h : CRaceView ���O������
//

#pragma once
#include "RaceDoc.h"
#include <vector>
#include <memory>
#include "MyButton.h"

#define TOTALHORSE 6
#define RACEDISTANCE 800
#define HORSE_INITPOS_X 5

class CRaceView : public CView
{
protected: // �ȱq�ǦC�ƫإ�
	CRaceView();
	DECLARE_DYNCREATE(CRaceView)

// �ݩ�
public:
	CRaceDoc* GetDocument() const;

// �@�~
public:

// �мg
public:
	virtual void OnDraw(CDC* pDC);  // �мg�H�yø���˵�
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �{���X��@
public:
	virtual ~CRaceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void ShowResult(int number, int distance);

protected:
	//CButton *m_Horse[TOTALHORSE];
	std::vector</* std::shared_ptr<CButton>*/ CMyButton*> m_Horse;

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
	CRect GetRect(int number, int distance);

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // RaceView.cpp ������������
inline CRaceDoc* CRaceView::GetDocument() const
   { return reinterpret_cast<CRaceDoc*>(m_pDocument); }
#endif

