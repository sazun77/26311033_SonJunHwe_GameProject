#pragma once

// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>
#include <string>

#include "Constants.h"
#define INPUT_NULL -777.7f

enum
{
	FILENAMEMAX = 300,
	VISIBLE = 1,
	INVISIBLE = 0,
};

class WindowImage
{
public:
	void Initialize(const char* fileName,const float x =INPUT_NULL,const float y= INPUT_NULL);
	void Draw();
	void Release();

	void SetImage(const char* fileName);
	void SetAlpha(int alpha);
	void SetPos(const float x, const float y);
	void SetPosX(const float x);
	void SetPosY(const float y);

	int GetIndex();
	int GetWidth();
	int GetHeight();
	float GetPosX();
	float GetPosY();

private:
	int m_index{};
	int m_width{};
	int m_height{};
	int m_alpha{VISIBLE};//투명도(밝기) 관련.

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