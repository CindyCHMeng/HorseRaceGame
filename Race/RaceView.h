
// RaceView.h : CRaceView 類別的介面
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
protected: // 僅從序列化建立
	CRaceView();
	DECLARE_DYNCREATE(CRaceView)

// 屬性
public:
	CRaceDoc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
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

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
	CRect GetRect(int number, int distance);

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // RaceView.cpp 中的偵錯版本
inline CRaceDoc* CRaceView::GetDocument() const
   { return reinterpret_cast<CRaceDoc*>(m_pDocument); }
#endif

