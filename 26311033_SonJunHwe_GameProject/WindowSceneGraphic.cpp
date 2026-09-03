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

#include "WindowSceneGraphic.h"
#include <iostream>


void WindowSceneGraphic::Render()
{
	VEC2 pos(width, height);
	//VEC2 pos(0, 0);
	g2_Draw2D(imageIdx, nullptr, &pos);	//pos는 생략 가능한 듯.
}

void WindowSceneGraphic::Setup()
{
	imageIdx = g2_TextureLoad(imageP);
	width = g2_TextureWidth(imageIdx);
	height = g2_TextureHeight(imageIdx);
}

void WindowSceneGraphic::End()
{
	g2_TextureRelease(imageIdx);
}