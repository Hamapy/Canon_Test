
// Canon Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCanonTestApp:
// �йش����ʵ�֣������ Canon Test.cpp
//

class CCanonTestApp : public CWinApp
{
public:
	CCanonTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCanonTestApp theApp;