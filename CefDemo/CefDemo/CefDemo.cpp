// CefDemo.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "CefDemo.h"
#include "MainWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	::CoInitialize(NULL);
	DuiLib::CPaintManagerUI::SetInstance(hInstance);
	DuiLib::CDuiString szResPath = DuiLib::CPaintManagerUI::GetCurrentPath();
	szResPath += _T("\\skin");
	DuiLib::CPaintManagerUI::SetResourcePath(szResPath);
	DuiLib::CPaintManagerUI::SetResourceZip(_T("ui.zip"));

	MainWnd* pMainWnd = new MainWnd(_T("MainWnd.xml"), _T("skin"));
	pMainWnd->Create(NULL, _T("CefDemo"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pMainWnd->CenterWindow();
	pMainWnd->ShowWindow();

	DuiLib::CPaintManagerUI::MessageLoop();
	::CoUninitialize();
	return 0;
}
