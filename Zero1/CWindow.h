#pragma once

#ifndef __CWINDOW_H__
#define __CWINDOW_H__

#include <windows.h>
#include <string>
#include "CImage.h"
#include "CTransform.h"

#define CWINDOW_CLASS_NAME TEXT("ZERO_WINDOW")

class CImage;

#define SCENCE_CLEAR true
#define SCENCE_NO_CLEAR false

#define DB_MODE_SINGLE   0
#define DB_MODE_GRADIENT 1

#define RD_STATE_WIREFRAME  1
#define RD_STATE_COLOR      2

class CWindow
{
public:
	bool CreateCWindow(int width, int height, std::wstring title);

	bool Run();
	void LockFPS(int &fps, int maxfps);
	static LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void BeginScence(bool clear = SCENCE_CLEAR);
	void EndScence();

	void DrawBackground(int mode = 0, UINT color = 0);


public:
	void TestScence1(bool clear = SCENCE_NO_CLEAR);  // point
	void TestScence2(bool clear = SCENCE_NO_CLEAR);  // line
	void TestScence3();							     // triangle
	void TestScence4();
	void TestScence5();
	void TestBox();

public:
	std::wstring windowName;
	int windowWidth, windowHeight;

	HINSTANCE  hInstance;
	HWND       hWnd;
	CImage     *pBackBuffer;
	CTransform transform;
	CMatrix    screen;
	bool	   backfaceCull;
	UINT       renderState;
};

inline void MemSetQuad(void *dest, UINT data, int count)
{
	__asm
	{
		mov edi, dest;   // 目的地
		mov ecx, count;  // 循环次数
		mov eax, data;   // 填入内容
		rep stosd;
	}
}

#endif // !__CWINDOW_H__