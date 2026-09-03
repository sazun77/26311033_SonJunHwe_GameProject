#pragma once
#include "WindowSceneGraphic.h"

class WindowMain
{
public:
	void Setup();
	int SetupRender();
	void Run();
	void Destroy();

private:
	const int m_x = 0;
	const int m_y = 0;
	const int m_width = 1280;
	const int m_height = 720;
	const char* m_name = "MyWindow\n";

	const int m_color = 0x77777777;
private:
	WindowSceneGraphic SceneGraphic{};
};

