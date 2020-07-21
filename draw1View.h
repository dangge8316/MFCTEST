
// draw1View.h: Cdraw1View 类的接口
//

#pragma once


class Cdraw1View : public CView
{
protected: // 仅从序列化创建
	Cdraw1View() noexcept;
	DECLARE_DYNCREATE(Cdraw1View)

// 特性
public:
	Cdraw1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cdraw1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	CPoint pointStart;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	bool m_bDraw;
};

#ifndef _DEBUG  // draw1View.cpp 中的调试版本
inline Cdraw1Doc* Cdraw1View::GetDocument() const
   { return reinterpret_cast<Cdraw1Doc*>(m_pDocument); }
#endif

