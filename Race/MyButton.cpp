// MyButton.cpp : 實作檔
//

#include "stdafx.h"
#include "Race.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_DELETEITEM()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// CMyButton 訊息處理常式




void CMyButton::PostNcDestroy()
{
	// TODO:  在此加入特定的程式碼和 (或) 呼叫基底類別
	delete this;
}


void CMyButton::OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct)
{
	// TODO:  在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CButton::OnDeleteItem(nIDCtl, lpDeleteItemStruct);
}


void CMyButton::OnDestroy()
{
	CButton::OnDestroy();

	// TODO:  在此加入您的訊息處理常式程式碼
}
