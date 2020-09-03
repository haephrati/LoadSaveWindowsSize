// WindowDoc.cpp : implementation of the CWindowDoc class
//

#include "stdafx.h"
#include "Window.h"

#include "WindowDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWindowDoc

IMPLEMENT_DYNCREATE(CWindowDoc, CDocument)

BEGIN_MESSAGE_MAP(CWindowDoc, CDocument)
	//{{AFX_MSG_MAP(CWindowDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowDoc construction/destruction

CWindowDoc::CWindowDoc()
{
	// TODO: add one-time construction code here

}

CWindowDoc::~CWindowDoc()
{
}

BOOL CWindowDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWindowDoc serialization

void CWindowDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWindowDoc diagnostics

#ifdef _DEBUG
void CWindowDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWindowDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWindowDoc commands
