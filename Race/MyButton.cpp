// MyButton.cpp : ��@��
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



// CMyButton �T���B�z�`��




void CMyButton::PostNcDestroy()
{
	// TODO:  �b���[�J�S�w���{���X�M (��) �I�s�����O
	delete this;
}


void CMyButton::OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct)
{
	// TODO:  �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��

	CButton::OnDeleteItem(nIDCtl, lpDeleteItemStruct);
}


void CMyButton::OnDestroy()
{
	CButton::OnDestroy();

	// TODO:  �b���[�J�z���T���B�z�`���{���X
}
