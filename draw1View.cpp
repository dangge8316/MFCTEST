
// draw1View.cpp: Cdraw1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw1.h"
#endif

#include "draw1Doc.h"
#include "draw1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cdraw1View

IMPLEMENT_DYNCREATE(Cdraw1View, CView)

BEGIN_MESSAGE_MAP(Cdraw1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cdraw1View 构造/析构

Cdraw1View::Cdraw1View() noexcept
{
	// TODO: 在此处添加构造代码

	pointStart = 0;
	m_bDraw = false;
}

Cdraw1View::~Cdraw1View()
{
}

BOOL Cdraw1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cdraw1View 绘图

void Cdraw1View::OnDraw(CDC* /*pDC*/)
{
	Cdraw1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void Cdraw1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cdraw1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cdraw1View 诊断

#ifdef _DEBUG
void Cdraw1View::AssertValid() const
{
	CView::AssertValid();
}

void Cdraw1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdraw1Doc* Cdraw1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdraw1Doc)));
	return (Cdraw1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cdraw1View 消息处理程序


void Cdraw1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	pointStart = point;
	m_bDraw = true;
	CView::OnLButtonDown(nFlags, point);
}


void Cdraw1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
	m_bDraw = false;
}


void Cdraw1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen newPen(PS_SOLID, 1, RGB(255, 0, 255));
	CPen* oldPen = dc.SelectObject(&newPen);
	if (m_bDraw)
	{
		dc.MoveTo(pointStart);
		dc.LineTo(point);
	}
	dc.SelectObject(oldPen);

	CView::OnMouseMove(nFlags, point);
}
