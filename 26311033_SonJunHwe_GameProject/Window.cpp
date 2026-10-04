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

using std::cout;
extern Window window;

// RenderDetailes은 일종의 update(), main()의 역할인 듯?
int AppRender()
{
	return window.Render();
}

int AppFrameMove()
{
	return window.FrameMove();
}

int AppKeyboard(uint8_t* keyP)
{
	return window.Keyboard(keyP);
}

int AppMouse(int x, int y, int z, int event)
{
	return window.Mouse(x,y,z,event);
}

int Window::Render()
{
	//for (auto& image : m_images)
	//{
	//	image.();
	//}

	return SUCCESS;
}

int Window::FrameMove()
{
	FrameMove_Update();

	FrameMove_Mouse();

	FrameMove_Keyboard();

	Sleep();
	return SUCCESS;
}

int Window::Keyboard(uint8_t* keyP)
{
	std::cout << keyP << '\n';

	return SUCCESS;
}

int Window::Mouse(int x, int y, int z, int event)
{
	std::cout << x << ' ';
	std::cout << y << ' ';
	std::cout << z << ' ';
	std::cout << event << '\n';
	return SUCCESS;
}

void Window::FrameMove_Update()
{
	std::cout << ++count << '\n';
	if (count > 60)
	{
		Close();
	}
}

void Window::FrameMove_Mouse()
{
	m_mouseX = g2_GetMouseX();
	m_mouseY = g2_GetMouseY();
	m_mouseZ = g2_GetMouseZ();

	if (g2_GetMouseEvent(LButton))
	{
		cout << "L click\n";
	}
	else if (g2_GetMouseEvent(RButton))
	{
		cout << "R click\n";

	}
	else if (g2_GetMouseEvent(MButton))
	{
		cout << "M click\n";
	}
	else
	{
		cout << "No click\n";
	}
}

void Window::FrameMove_Keyboard()
{
	const KEYCODE* pKeyboard = g2_GetKeyboard();

	for (int i = 9; i < 128; ++i)
	{
		if (pKeyboard[i])
		{
			printf("You Pressed %d key!!!\n", i);
		}
	}
}

void Window::Sleep(int delay)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

void Window::Close()
{
	PostMessage(m_hWnd, WM_CLOSE, 0, 0);
}

void Window::Setup()
{
	// SDK 초기화
	std::cout << "Initialliseing SDK\n";
	g2_InitSdk();
	
	// 윈도우 색 설정.
	std::cout << "Window color set\n";
	g2_SetClearColor(m_color);
	
	//화면 출력,update,키보드 이벤트,마우스 이벤트 함수 등록.
	std::cout << "Set Render\n";
	g2_SetRender(AppRender);
	std::cout << "Set Update\n";
	g2_SetFrameMove(AppFrameMove);
	std::cout << "Set Keyboard event\n";
	g2_SetKeyboard(AppKeyboard);
	std::cout << "Set mouse event\n";
	g2_SetMouse(AppMouse);
	
	// 윈도우 생성
	std::cout << "Createing Window\n";
	g2_CreateWin(m_pos.x, m_pos.y, m_width, m_height, m_name);
	
	// 윈도우 핸들 받아오기
	// 이거 있어야 창 닫기 가능.
	m_hWnd = g2_GetHwnd();
}

void Window::Run()
{
	std::cout << "Running Window\n";
	g2_Run();	// 여기서 명령을 추가로 하는 법을 모르겠음.
}

void Window::Destroy()
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

