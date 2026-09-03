// link the 2d game library
#if defined(_DEBUG)
#if defined(_M_X64) // 64-bit 아키텍처
#pragma comment(lib, "glc2d_x64_debug.lib")
#elif defined(_M_IX86) // 32-bit 아키텍처
#pragma comment(lib, "glc2d_win32_debug.lib")
#endif
#else
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_release.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_release.lib")
#endif
#endif

// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>
//
#include "WindowMain.h"
#include <iostream>

void WindowMain::Setup()
{
	// SDK 초기화
	std::cout << "Initiallise SDK\n";
	g2_InitSdk();

}

void WindowMain::Create()
{
	// 윈도우 색 설정.
	g2_SetClearColor(WindowMain::color);
	// 윈도우 생성
	std::cout << "Create Window\n";
	g2_CreateWin(WindowMain::x, WindowMain::y, WindowMain::width, WindowMain::height, WindowMain::name);
}

void WindowMain::Run()
{
	std::cout << "Running Window\n";
	g2_Run();
}

void WindowMain::Destroy()
{
	std::cout << "Desroyed Window\n";
	g2_DestroyWin();
}
