#pragma once
#include "Constants.h"
#include "glc2d.h"

class TextureDrawer
{
public:
	void Setup(const char* fileName);
	void RenderMain();
	void End();

	void SetPos(const int x,const int y);

	int GetWidth();
	int GetHeight();
	int GetIndex();
	int GetX();
	int GetY();
private:
	int m_imageIdx{};
	int m_width{};
	int m_height{};
	VEC2 m_pos{};

	char m_imageP[FILENAMEMAX]{};
};

//int RenderMain()
//{
//	VEC2 pos(400, 200);
//
//	g2_Draw2D(nTx, NULL, &pos);
//
//	return 0;
//}