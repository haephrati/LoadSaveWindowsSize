// Window.h : main header file for the WINDOW application
//

#if !defined(AFX_WINDOW_H__C4E365AF_533D_41CE_8125_6349760EA9CB__INCLUDED_)
#define AFX_WINDOW_H__C4E365AF_533D_41CE_8125_6349760EA9CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWindowApp:
// See Window.cpp for the implementation of this class
//

class CWindowApp : public CWinApp
{

// BEGIN WINDOW PLACEMENT CODE

private:
	WINDOWPLACEMENT m_WP;
public:
	const WINDOWPLACEMENT& GetWP(void) const;
	void PutWP(const WINDOWPLACEMENT& newval);
protected:
	virtual void ReadConfig(void);
	virtual void WriteConfig(void);
	virtual void ReadWindowConfig(void);
	virtual void WriteWindowConfig(void);

// END WINDOW PLACEMENT CODE

public:
	CWindowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWindowApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOW_H__C4E365AF_533D_41CE_8125_6349760EA9CB__INCLUDED_)
