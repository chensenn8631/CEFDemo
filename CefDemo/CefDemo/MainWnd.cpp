#include "StdAfx.h"
#include "MainWnd.h"


MainWnd::MainWnd(LPCTSTR szXmlFile, LPCTSTR szXmlFolder) : m_szXmlFile(szXmlFile), m_szXmlFolder(szXmlFolder)
{
}


MainWnd::~MainWnd(void)
{
}

void MainWnd::InitWindow()
{

}
void MainWnd::Notify(DuiLib::TNotifyUI& msg)
{
	return __super::Notify(msg);
}

DuiLib::CDuiString MainWnd::GetSkinFolder() 
{
	return m_szXmlFolder;
}

DuiLib::CDuiString MainWnd::GetSkinFile()
{
	return m_szXmlFile;
}

LPCTSTR MainWnd::GetWindowClassName(void) const
{
	return _T("MainWnd");
}

LRESULT MainWnd::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return __super::HandleCustomMessage( uMsg, wParam, lParam, bHandled);
}

void MainWnd::OnClick(DuiLib::TNotifyUI& msg) 
{
	DuiLib::CDuiString szName = msg.pSender->GetName();
	if(msg.sType == _T("click"))
	{
		if(szName == _T("close_btn"))
		{
			::PostQuitMessage(0);
		}
	}
	return __super::OnClick(msg);
}