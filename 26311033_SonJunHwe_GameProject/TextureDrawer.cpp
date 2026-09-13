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

// 좌표를 입력하면 해당 위치에 이미지 표시.
// 렌더를 안하면 바로 다음render()에서 아라야시키 당하는 듯.
// m_pos는 생략 가능한 듯.
void TextureDrawer::RenderMain()
{
	g2_Draw2D(m_imageIdx, nullptr, &m_pos);	
}

// 이후에 활용할 수 있도록 이미지의 주소,인덱스,너비,폭을 설정함.
void TextureDrawer::Setup(const char* fileName)
{
	strcpy(m_imageP, fileName);
	m_imageIdx = g2_TextureLoad(m_imageP);
	m_width = g2_TextureWidth(m_imageIdx);
	m_height = g2_TextureHeight(m_imageIdx);
}


// 이걸 호출하면 이후에 Render해도 이미지가 나타나지 않음.
// 다만 Setup을 다시 해주면 부활함.
//	- 정확히는 유사한 객체를 다시 만드는 것이라 할 수 있을 듯.
void TextureDrawer::End()
{
	g2_TextureRelease(m_imageIdx);
}

void TextureDrawer::SetPos(const int x, const int y)
{
	m_pos.x = static_cast<float>(x);
	m_pos.y = static_cast<float>(y);
}

int TextureDrawer::GetWidth()
{
	return m_width;
}

int TextureDrawer::GetHeight()
{
	return m_height;
}

int TextureDrawer::GetIndex()
{
	return m_imageIdx;
}

int TextureDrawer::GetX()
{
	return static_cast<int>(m_pos.x);
}

int TextureDrawer::GetY()
{
	return static_cast<int>(m_pos.y);
}
