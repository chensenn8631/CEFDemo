#include "stdafx.h"
#include "UIButtonHtml.h"

namespace DuiLib
{
	CButtonHtmlUI::CButtonHtmlUI()
	{
		SetShowHtml(true);
	}

	void CButtonHtmlUI::DoEvent(DuiLib::TEventUI& event)
	{
		//������ʱ��ʾ�»���
		if( event.Type == UIEVENT_MOUSEENTER ) 
		{
			CDuiString str = GetText();
			CDuiString strTemp ;
			
			strTemp.Format(_T("{u}%s{/u}"), str);
			SetText(strTemp);
		}

		//�������ʱȥ���»���
		if( event.Type == UIEVENT_MOUSELEAVE ) 
		{
			CDuiString str = GetText();
			str.Replace(_T("{u}"), _T(""));
			str.Replace(_T("{/u}"), _T(""));
			DWORD textColor = GetTextColor();
			SetText(str);
		}
		
		__super::DoEvent(event);
	}


}