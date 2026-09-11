#pragma once
#include "TextureDrawer.h"


int Render();


class WindowMain
{
public:
	int RenderDetailes();
	void Setup();
	void Run();
	void Destroy();

private:
	VEC2 m_pos{};
	const int m_width = 1280;
	const int m_height = 720;
	const char* m_name = "MyWindow\n";

	const int m_color = 0x77777777;
private:
	
	TextureDrawer m_image_test{};
	TextureDrawer m_image_test02{};

};

