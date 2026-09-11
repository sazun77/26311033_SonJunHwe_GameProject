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

extern WindowMain window;
float testPos{ 0.0f };
// 랜더 함수. SetupRender를 호출함.
// SetupRender은 

void WindowMain::Setup()
{
	// SDK 초기화
	std::cout << "Initialliseing SDK\n";
	g2_InitSdk();
	// 윈도우 색 설정.
	std::cout << "Window color set\n";
	g2_SetClearColor(m_color);
	//화면 출력 함수 등록.
	g2_SetRender(Render);
	// 윈도우 생성
	std::cout << "Createing Window\n";


	int x = m_pos.x;
	int y = m_pos.y;
	g2_CreateWin(x,y, m_width, m_height, m_name);

	// 씬 셋업.
	std::cout << "Scene Graphic setup\n";

	m_image_test.Setup("Texture/tst.png");
	m_image_test02.Setup("Texture/Icon_Atk.png");

}

int Render()
{
	++testPos;
	return window.RenderDetailes();
}

int WindowMain::RenderDetailes()
{
	std::cout << "Rendering start\n";
	if (testPos > 10.0f)
	{
		m_image_test02.Setup("Texture/Icon_Atk.png");
	}
	else if (testPos > 5.0f)
	{
		m_image_test02.End();
	}
	m_image_test.Render({ testPos,testPos });
	m_image_test02.Render({ 400.0f - testPos,300.0f - testPos });
	return 0;
}

void WindowMain::Run()
{
	std::cout << "Running Window\n";
	g2_Run();	// 여기서 명령을 추가로 하는 법을 모르겠음.
	std::cout << "Running End\n";
}

void WindowMain::Destroy()
{
	std::cout << "Desroying Window\n";
	g2_DestroyWin();
}
