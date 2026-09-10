#pragma once
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

class WindowImage
{
public:
	// m_imageIdx,m_width,m_height,m_imageFile을 설정함.
	void Setup(const char* imageFile = "Texture/tst.png");
	void Render();
	void End();

private:
	int m_imageIdx{};
	int m_width{};
	int m_height{};

	const char* m_imageFile{};
};

//    g2_SetRender(Render);
