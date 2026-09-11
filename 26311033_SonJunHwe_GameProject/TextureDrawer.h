#pragma once

// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>
#include <string>

class TextureDrawer
{
public:
	void Setup(const char* fileName);
	void Render(const VEC2& pos);
	void End();
private:
	int m_imageIdx{};
	int m_width{};
	int m_height{};
	VEC2 m_pos{};
	
	char m_imageP[250]{};
};

//int Render()
//{
//	VEC2 pos(400, 200);
//
//	g2_Draw2D(nTx, NULL, &pos);
//
//	return 0;
//}