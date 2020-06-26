#pragma once
#include <list>
#include "afxwin.h"



// CResultView 表單檢視

class CResultView : public CFormView
{
	DECLARE_DYNCREATE(CResultView)

protected:
	CResultView();           // 動態建立所使用的保護建構函式
	virtual ~CResultView();

public:
	enum { IDD = IDD_RESULTVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	void ShowResult(std::list<int> rank);
	void InitialButton();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	
protected:
	CButton m_StartButton;
	CButton m_StopButton;
	CStatic m_RankText1;
	CStatic m_RankText2;
	CStatic m_RankText3;
	CStatic m_RankText4;
	CStatic m_RankText5;
	CStatic m_RankText6;
};


