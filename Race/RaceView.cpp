
// RaceView.cpp : CRaceView ���O����@
//

#include "stdafx.h"
// SHARED_HANDLERS �i�H�w�q�b��@�w���B�Y�ϩM�j�M�z�����B�z�`����
// ATL �M�פ��A�ä��\�P�ӱM�צ@�Τ��{���X�C
#ifndef SHARED_HANDLERS
#include "Race.h"
#endif

#include "RaceDoc.h"
#include "RaceView.h"
#include <map>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRaceView

IMPLEMENT_DYNCREATE(CRaceView, CView)

BEGIN_MESSAGE_MAP(CRaceView, CView)
	// �зǦC�L�R�O
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CRaceView �غc/�Ѻc

CRaceView::CRaceView()
{
	// TODO:  �b���[�J�غc�{���X
	
}

CRaceView::~CRaceView()
{
}

BOOL CRaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	return CView::PreCreateWindow(cs);
}

// CRaceView �yø

void CRaceView::OnDraw(CDC* /*pDC*/)
{
	CRaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  �b���[�J��͸�ƪ��yø�{���X
}


// CRaceView �C�L

BOOL CRaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �w�]���ǳƦC�L�{���X
	return DoPreparePrinting(pInfo);
}

void CRaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  �[�J�C�L�e�B�~����l�]�w
}

void CRaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  �[�J�C�L�᪺�M���{���X
}


// CRaceView �E�_

#ifdef _DEBUG
void CRaceView::AssertValid() const
{
	CView::AssertValid();
}

void CRaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRaceDoc* CRaceView::GetDocument() const // ���O�D��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRaceDoc)));
	return (CRaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CRaceView �T���B�z�`��

CRect CRaceView::GetRect(int number, int distance)
{
	CRect tempRect;

	tempRect.left = HORSE_INITPOS_X + distance;
	tempRect.right = tempRect.left + 50;
	tempRect.top = 7 + ((number - 1) * 60);
	tempRect.bottom = 57 + ((number - 1) * 60);

	return tempRect;
}


void CRaceView::ShowResult(int number, int distance)
{
	if (distance > RACEDISTANCE)
		distance = RACEDISTANCE;

	CRect tempRect = GetRect(number, distance);

	m_Horse[number - 1]->MoveWindow(tempRect);
	m_Horse[number - 1]->UpdateWindow();
}


int CRaceView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	for (int i = 0; i < TOTALHORSE; i++)
	{
		//std::shared_ptr <CButton> tempHorse(new CButton());
		m_Horse.push_back(new CMyButton);

		switch (i + 1)
		{
			case 1:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(1, 0), this, IDC_BUTTON_Horse1);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE1), IMAGE_ICON, 48, 48, 0));
				break;

			case 2:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(2, 0), this, IDC_BUTTON_Horse2);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE2), IMAGE_ICON, 48, 48, 0));
				break;

			case 3:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(3, 0), this, IDC_BUTTON_Horse3);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE3), IMAGE_ICON, 48, 48, 0));
				break;

			case 4:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(4, 0), this, IDC_BUTTON_Horse4);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE4), IMAGE_ICON, 48, 48, 0));
				break;

			case 5:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(5, 0), this, IDC_BUTTON_Horse5);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE5), IMAGE_ICON, 48, 48, 0));
				break;

			case 6:
				m_Horse[i]->Create(_T("Horse"), WS_CHILD | WS_VISIBLE | BS_ICON, GetRect(6, 0), this, IDC_BUTTON_Horse6);
				m_Horse[i]->SetIcon((HICON)::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_HORSE6), IMAGE_ICON, 48, 48, 0));
				break;

			default:
				break;
		}
	}

	return 0;
}


void CRaceView::OnDestroy()
{
	CView::OnDestroy();

	// TODO:  �b���[�J�z���T���B�z�`���{���X
	for (size_t i = 0; i < m_Horse.size(); i++)
	{
		delete m_Horse.at(i);
	}
	m_Horse.clear();
}
