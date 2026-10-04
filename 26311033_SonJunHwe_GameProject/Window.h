#pragma once

#include <vector>
#include "glc2d.h"
#include "TextureDrawer.h"

enum
{
	GAMETICK = 300,
};

 int RenderMain();

class Window
{

public:
	//void RenderDetailes();
	void Main_Start();
	void Main_Setup();
	void Main_Rendering();
	void Main_Sleep(int delay=GAMETICK);
	void Main_Destroy();

	void SetPos(float x, float y);
	void SetPosX(float x);
	void SetPosY(float y);

	float GetPosX();
	float GetPosY();
	int GetWidth();
	int GetHeight();

	
private:
	VEC2 m_pos{};
	const int m_width{1280};
	const int m_height{ 720 };
	const char* m_name{ "PressSpace" };

	const int m_color{ 0x77777777 };
};

