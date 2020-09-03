// Window.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Window.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "WindowDoc.h"
#include "WindowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWindowApp

BEGIN_MESSAGE_MAP(CWindowApp, CWinApp)
	//{{AFX_MSG_MAP(CWindowApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowApp construction

CWindowApp::CWindowApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWindowApp object

CWindowApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWindowApp initialization

BOOL CWindowApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_WINDOWTYPE,
		RUNTIME_CLASS(CWindowDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CWindowView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

// BEGIN WINDOW PLACEMENT CODE

	ReadConfig(); 
		
	m_pMainWnd->SetWindowPlacement(&m_WP);

// END WINDOW PLACEMENT CODE

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CWindowApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CWindowApp message handlers


// BEGIN WINDOW PLACEMENT CODE

int CWindowApp::ExitInstance() 
{
	WriteConfig();
		
	// any other code you need before exit
	
	return CWinApp::ExitInstance();
}

const WINDOWPLACEMENT& CWindowApp::GetWP(void) const
{
	return m_WP;
}

void CWindowApp::PutWP(const WINDOWPLACEMENT& newval)
{	
	m_WP=newval;
	m_WP.length=sizeof(m_WP); // validation ;)
}

void CWindowApp::ReadConfig(void)
{
	ReadWindowConfig();
}

void CWindowApp::WriteConfig(void)
{
	WriteWindowConfig();
}

void CWindowApp::ReadWindowConfig(void)
{
	WINDOWPLACEMENT wp;
	
	wp.length=sizeof(wp);
	m_pMainWnd->GetWindowPlacement(&wp);

	m_WP.length=sizeof(m_WP);
	m_WP.showCmd=GetProfileInt(L"Window",L"show",wp.showCmd);
	m_WP.flags=GetProfileInt(L"Window",L"flags",wp.flags);
	m_WP.ptMinPosition.x=GetProfileInt(L"Window",L"minposx",
		wp.ptMinPosition.x);
	m_WP.ptMinPosition.y=GetProfileInt(L"Window",L"minposy",
		wp.ptMinPosition.y);
	m_WP.ptMaxPosition.x=GetProfileInt(L"Window",L"maxposx",
		wp.ptMaxPosition.x);
	m_WP.ptMaxPosition.y=GetProfileInt(L"Window",L"maxposy",
		wp.ptMaxPosition.y);
	m_WP.rcNormalPosition.left=GetProfileInt(L"Window",L"left",
		wp.rcNormalPosition.left);
	m_WP.rcNormalPosition.top=GetProfileInt(L"Window",L"top",
		wp.rcNormalPosition.top);
	m_WP.rcNormalPosition.right=GetProfileInt(L"Window",L"right",
		wp.rcNormalPosition.right);
	m_WP.rcNormalPosition.bottom=GetProfileInt(L"Window",L"bottom",
		wp.rcNormalPosition.bottom);

	CRect rcTemp;
	CRect rcScreen(0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));

	// ::SystemParametersInfo(SPI_GETWORKAREA) gives us the screen space
	// minus the system taskbar and application toolbars, which is what 
	// we want our application to fit into.
	
	::SystemParametersInfo(SPI_GETWORKAREA,0,&rcScreen,0);

	// Normalise the existing rectangle, and force equality

	rcTemp=m_WP.rcNormalPosition;
	rcTemp.NormalizeRect();
	m_WP.rcNormalPosition=rcTemp;

	// See if any part of the window is on the screen

	if(::IntersectRect(&m_WP.rcNormalPosition, &rcTemp, &rcScreen))
	{
		if(rcTemp!=m_WP.rcNormalPosition)
		{	// some part of the window is off the screen
			if(rcTemp.left<rcScreen.left) 		// off the left edge
				rcTemp.OffsetRect(rcScreen.left-rcTemp.left,0);
			if(rcTemp.right>rcScreen.right) 	// off the right edge
				rcTemp.OffsetRect(rcScreen.right-rcTemp.right,0);
			if(rcTemp.left<rcScreen.left) 		// won't fit, shrink
				rcTemp.left=rcScreen.left;
			if(rcTemp.top<rcScreen.top) 		// off the top edge
				rcTemp.OffsetRect(0,rcScreen.top-rcTemp.top);
			if(rcTemp.bottom>rcScreen.bottom) 	// off the bottom edge
				rcTemp.OffsetRect(0,rcScreen.bottom-rcTemp.bottom);
			if(rcTemp.top<rcScreen.top) 		// won't fit, shrink
				rcTemp.top=rcScreen.top;
			m_WP.rcNormalPosition=rcTemp;
		}
	}
	else
	{	// entire window is offscreen
		m_WP=wp;
	}

	if(m_WP.showCmd==SW_MINIMIZE && wp.showCmd!=SW_MINIMIZE)
	{	// check default to see if this was requested
		m_WP.showCmd=SW_RESTORE;		// set restore flag
	}

	if(m_WP.showCmd!=SW_MAXIMIZE && wp.showCmd==SW_MAXIMIZE)
	{	// check default to see if this was requested
		m_WP.showCmd=SW_MAXIMIZE;		// set maximise flag
	}
}

void CWindowApp::WriteWindowConfig(void)
{
	WriteProfileInt(L"Window",L"show",m_WP.showCmd);
	WriteProfileInt(L"Window",L"flags",m_WP.flags);
	WriteProfileInt(L"Window",L"minposx",m_WP.ptMinPosition.x);
	WriteProfileInt(L"Window", L"minposy",m_WP.ptMinPosition.y);
	WriteProfileInt(L"Window", L"maxposx",m_WP.ptMaxPosition.x);
	WriteProfileInt(L"Window", L"maxposy",m_WP.ptMaxPosition.y);
	WriteProfileInt(L"Window", L"left",m_WP.rcNormalPosition.left);
	WriteProfileInt(L"Window", L"top",m_WP.rcNormalPosition.top);
	WriteProfileInt(L"Window", L"right",m_WP.rcNormalPosition.right);
	WriteProfileInt(L"Window", L"bottom",m_WP.rcNormalPosition.bottom);
}

// END WINDOW PLACEMENT CODE
