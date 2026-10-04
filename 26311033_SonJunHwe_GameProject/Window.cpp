//// link the 2d game library
//#if defined(_DEBUG)
//#if defined(_M_X64) // 64-bit 아키텍처
//#pragma comment(lib, "glc2d_x64_debug.lib")
//#elif defined(_M_IX86) // 32-bit 아키텍처
//#pragma comment(lib, "glc2d_win32_debug.lib")
//#endif
//#else
//#if defined(_M_X64)
//#pragma comment(lib, "glc2d_x64_release.lib")
//#elif defined(_M_IX86)
//#pragma comment(lib, "glc2d_win32_release.lib")
//#endif
//#endif
//
//// include the 2d game header file
//#include "glc2d.h"
//#include <stdio.h>
//
#include <iostream>
#include <thread>
#include <time.h>
#include "glc2d.h"

#include "Window.h"
#include "SoundEffectter.h"

extern Window window;

// RenderDetailes은 일종의 update(), main()의 역할인 듯?
int RenderMain()
{
	while (true)
	{
		window.Main_Rendering();

		if (true)
		{
			window.Main_Destroy();
			break;
		}

		window.Main_Sleep();
	}

	return 1;
}
//void Window::RenderDetailes()
//{
//	std::cout << "Rendering start..."<<time(NULL)<<'\n';
//
//	for (auto& image : m_images)
//	{
//		image.RenderMain();
//	}
//}

void Window::Main_Rendering()
{
	//for (auto& image : m_images)
	//{
	//	image.RenderMain();
	//}
}

void Window::Main_Sleep(int delay)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

void Window::Main_Setup()
{
	// SDK 초기화
	std::cout << "Initialliseing SDK\n";
	g2_InitSdk();
	// 윈도우 색 설정.
	std::cout << "Window color set\n";
	g2_SetClearColor(m_color);
	//화면 출력 함수 등록.
	std::cout << "Set Render\n";
	g2_SetRender(RenderMain);
	// 윈도우 생성
	std::cout << "Createing Window\n";
	g2_CreateWin(m_pos.x, m_pos.y, m_width, m_height, m_name);
}

void Window::Main_Start()
{
	Main_Setup();

	std::cout << "Running Window\n";
	g2_Run();	// 여기서 명령을 추가로 하는 법을 모르겠음.
}

void Window::Main_Destroy()
{
	std::cout << "Desroying Window\n";
	g2_DestroyWin();
}

void Window::SetPos(float x, float y)
{
	SetPosX(x);
	SetPosY(y);
}

void Window::SetPosX(float x)
{
	m_pos.x = x;
}

void Window::SetPosY(float y)
{
	m_pos.y = y;
}

float Window::GetPosX()
{
	return m_pos.x;
}

float Window::GetPosY()
{
	return m_pos.y;
}

int Window::GetWidth()
{
	return m_width;
}
int Window::GetHeight()
{
	return m_height;
}

