// WindowView.h : interface of the CWindowView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWVIEW_H__0DD24DBB_6A77_4E42_9051_D6F931195345__INCLUDED_)
#define AFX_WINDOWVIEW_H__0DD24DBB_6A77_4E42_9051_D6F931195345__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWindowView : public CView
{
protected: // create from serialization only
	CWindowView();
	DECLARE_DYNCREATE(CWindowView)

// Attributes
public:
	CWindowDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWindowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWindowView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WindowView.cpp
inline CWindowDoc* CWindowView::GetDocument()
   { return (CWindowDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWVIEW_H__0DD24DBB_6A77_4E42_9051_D6F931195345__INCLUDED_)
