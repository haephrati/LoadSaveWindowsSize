// WindowDoc.h : interface of the CWindowDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWDOC_H__6DC2CB08_2625_414F_A363_E6E7C2828BCA__INCLUDED_)
#define AFX_WINDOWDOC_H__6DC2CB08_2625_414F_A363_E6E7C2828BCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWindowDoc : public CDocument
{
protected: // create from serialization only
	CWindowDoc();
	DECLARE_DYNCREATE(CWindowDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWindowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWindowDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWDOC_H__6DC2CB08_2625_414F_A363_E6E7C2828BCA__INCLUDED_)
