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

#include "TextureDrawer.h"
#include <iostream>
#include <string.h>

void TextureDrawer::Render()
{
	//VEC2 pos(0, 0);
	g2_Draw2D(imageIdx, nullptr, &m_pos);	//pos는 생략 가능한 듯.
}

void TextureDrawer::Setup(const char* fileName)
{
	strcpy(imageP, fileName);
	imageIdx = g2_TextureLoad(imageP);
	width = g2_TextureWidth(imageIdx);
	height = g2_TextureHeight(imageIdx);
}

void TextureDrawer::SetPosition(const VEC2& pos)
{
	this->m_pos = pos;
}

void TextureDrawer::End()
{
	//g2_TextureRelease(imageIdx);
}