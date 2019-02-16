#pragma once
#include "stdafx.h"

class MainWnd : public DuiLib::WindowImplBase
{
public:
	MainWnd(LPCTSTR szXmlFile, LPCTSTR szXmlFolder);
	~MainWnd(void);
	virtual void InitWindow();
	virtual void Notify(DuiLib::TNotifyUI& msg);
	virtual DuiLib::CDuiString GetSkinFolder();
	virtual DuiLib::CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void) const;
	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	//DUI_DECLARE_MESSAGE_MAP()
	virtual void OnClick(DuiLib::TNotifyUI& msg);
private:
	DuiLib::CDuiString m_szXmlFile;
	DuiLib::CDuiString m_szXmlFolder;
};

