﻿#pragma once
#include <GdiPlus.h>
using namespace Gdiplus;
class CTextRenderer
{
public:
	CTextRenderer();
	~CTextRenderer();
	bool Init();
	bool Paint();
	ULONG_PTR GetgpToken()
	{
		return m_gpToken;
	}
	int TextDraw(Graphics *graphics, const wchar_t *contextText, int textAlign, wchar_t *fontName, int fontStyle, int fntSize, int outlineInThick, int outlineOutThick, Color textColor, Color outlineInColor, Color outlineOutColor, Color shadowColor, bool textVisible, bool outlineInVisible, bool outlineOutVisible, bool shadowVisible, Rect *layoutRect);

	void SetName(const wchar_t *str)
	{
		int nLen = wcslen(str);
		if (nLen > 1000) nLen = 1000;
		memcpy(szName, str, nLen * 2);
		szName[nLen] = 0x00;
	}
	wchar_t *GetName()
	{
		return szName;
	}

	void SetNameT(const wchar_t *str)
	{
		int nLen = wcslen(str);
		if (nLen > 1000) nLen = 1000;
		memcpy(szNameT, str, nLen * 2);
		szNameT[nLen] = 0x00;
	}
	wchar_t *GetNameT()
	{
		return szNameT;
	}

	void SetText(const wchar_t *str)
	{
		int nLen = wcslen(str);
		if (nLen > 1000) nLen = 1000;
		memcpy(szText, str, nLen * 2);
		szText[nLen] = 0x00;
	}
	wchar_t *GetText()
	{
		return szText;
	}

	void SetTextT(const wchar_t *str)
	{
		int nLen = wcslen(str);
		if (nLen > 1000) nLen = 1000;
		memcpy(szTextT, str, nLen * 2);
		szTextT[nLen] = 0x00;
	}
	wchar_t *GetTextT()
	{
		return szTextT;
	}

	void SetContext()
	{
		int nNameLen, nTextLen;
		nNameLen = wcslen(szName);
		if (nNameLen > 1000) nNameLen = 1000;
		memcpy(szContext, szName, nNameLen * 2);

		nTextLen = wcslen(szText);
		if (nTextLen > 1000) nTextLen = 1000;
		memcpy(szContext + nNameLen, szText, nTextLen * 2);
		szContext[nNameLen + nTextLen] = 0x00;
	}
	wchar_t *GetContext()
	{
		return szContext;
	}

	void SetContextT()
	{
		int nNameLen, nTextLen;
		nNameLen = wcslen(szNameT);
		if (nNameLen > 1000) nNameLen = 1000;
		memcpy(szContextT, szNameT, nNameLen * 2);

		nTextLen = wcslen(szTextT);
		if (nTextLen > 1000) nTextLen = 1000;
		memcpy(szContextT + nNameLen, szTextT, nTextLen * 2);
		szContextT[nNameLen + nTextLen] = 0x00;
	}
	wchar_t *GetContextT()
	{
		return szContextT;
	}
	
	void SetTextSet(const wchar_t *Name, const wchar_t *NameT, const wchar_t *Text, const wchar_t *TextT)
	{
		SetName(Name);
		SetNameT(NameT);
		SetText(Text);
		SetTextT(TextT);
		SetContext();
		SetContextT();
	}

	void SetTextColorFromConfig();

	void SetTextColor(int type, int n, int c)
	{
		switch (type)
		{
		case CFG_NAME:
		{
			if (n == CFG_A) dwNameA = c;
			else if (n == CFG_B) dwNameB = c;
			else if (n == CFG_C) dwNameC = c;
			else if (n == CFG_S) dwNameS = c;
		}
			break;
		case CFG_ORG:
		{
			if (n == CFG_A) dwOrgA = c;
			else if (n == CFG_B) dwOrgB = c;
			else if (n == CFG_C) dwOrgC = c;
			else if (n == CFG_S) dwOrgS = c;
		}
			break;
		case CFG_TRANS:
		{
			if (n == CFG_A) dwTransA = c;
			else if (n == CFG_B) dwTransB = c;
			else if (n == CFG_C) dwTransC = c;
			else if (n == CFG_S) dwTransS = c;
		}
			break;
		case CFG_BACKGROUND:
		{
			dwBGColor = c;
		}
			break;
		case CFG_BORDER:
		{
			dwBorderColor = c;
		}
			break;
		}
	}
	//std::wstring *szName, *szNameT, *szText, *szTextT, *szContext, *szContextT;
private:
	ULONG_PTR m_gpToken;
	HBITMAP hBitmap;
	BITMAPINFOHEADER bmih;
	int hBitmap_X = 0;
	int hBitmap_Y = 0;
	//HDC hMemDC;

	wchar_t szName[1024];
	wchar_t szNameT[1024];
	wchar_t szText[1024];
	wchar_t szTextT[1024];
	wchar_t szContext[2048];
	wchar_t szContextT[2048];

	DWORD dwNameA;
	DWORD dwNameB;
	DWORD dwNameC;
	DWORD dwNameS;

	DWORD dwOrgA;
	DWORD dwOrgB;
	DWORD dwOrgC;
	DWORD dwOrgS;

	DWORD dwTransA;
	DWORD dwTransB;
	DWORD dwTransC;
	DWORD dwTransS;

	DWORD dwBGColor;
	DWORD dwBorderColor;
};

