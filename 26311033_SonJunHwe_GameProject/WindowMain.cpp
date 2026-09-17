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
#include <iostream>
#include <thread>
#include <time.h>
#include "WindowMain.h"
#include "SoundEffectter.h"

extern WindowMain window;
extern SoundEffectter testSound;
float testPos{ 0.0f };
// 랜더 함수. RenderDetailes를 호출함.
// RenderDetailes은 일종의 update(), main()의 역할인 듯?
int RenderMain()
{
	const KEYCODE* pKey = g2_GetKeyboard();

	if (pKey[VK_SPACE])
	{
		std::cout << "sound Played." << pKey << '\n';
		testSound.SoundPlay();

		window.m_images[0].SetPos(g2_GetMouseX(), g2_GetMouseY());
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(GAMETICK));
	return window.RenderDetailes();
}
int WindowMain::RenderDetailes()
{
	std::cout << "Rendering start..."<<time(NULL)<<'\n';

	for (auto& image : m_images)
	{
		image.RenderMain();
	}

	return SUCCESS;
}

void WindowMain::Setup()
{
	// SDK 초기화
	std::cout << "Initialliseing SDK\n";
	g2_InitSdk();
	// 윈도우 색 설정.
	std::cout << "Window color set\n";
	g2_SetClearColor(m_color);
	//화면 출력 함수 등록.
	g2_SetRender(RenderMain);
	// 윈도우 생성
	std::cout << "Createing Window\n";



	g2_CreateWin(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_width, m_height, m_name);

	// 씬 셋업.
	std::cout << "Scene Graphic setup\n";
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

// 초기 좌표를 입력하지 않을 경우 초기 좌표는 (0,0)으로 설정됩니다.
// 추가된 요소가 몇 번째 인덱스인지를 반환합니다.
int WindowMain::SetImageNew(const char* fileP, const int x, const int y)
{
	TextureDrawer td{};
	td.Setup(fileP);
	td.SetPos(x, y);

	m_images.push_back(td);

	return static_cast<int>(m_images.size()) - 1;
}

void WindowMain::SetImagePos(const int imageIdx, const int x, const int y)
{
	m_images[imageIdx].SetPos(x, y);
}

int WindowMain::GetWidth()
{
	return m_width;
}
int WindowMain::GetHeight()
{
	return m_height;
}

int WindowMain::GetImageWidth(const int imageIdx)
{
	return m_images[imageIdx].GetWidth();
}

int WindowMain::GetImageHeight(const int imageIdx)
{
	return m_images[imageIdx].GetHeight();
}

int WindowMain::GetImageX(const int imageIdx)
{
	return m_images[imageIdx].GetX();
}

int WindowMain::GetImageY(const int imageIdx)
{
	return m_images[imageIdx].GetY();
}
