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

#include "WindowImage.h"
#include <iostream>



void WindowImage::Setup(const char* imageFile)
{
	m_imageIdx = g2_TextureLoad(imageFile);
	m_width = g2_TextureWidth(m_imageIdx);
	m_height = g2_TextureHeight(m_imageIdx);
	m_imageFile = imageFile;
}


void WindowImage::Render()
{	
	VEC2 pos(m_width, m_height);
	//VEC2 pos(0, 0);
	g2_Draw2D(m_imageIdx, nullptr, &pos);	//pos는 생략 가능한 듯.
}


void WindowImage::End()
{
	g2_TextureRelease(m_imageIdx);
}
