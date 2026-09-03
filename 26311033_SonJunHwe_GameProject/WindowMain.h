#pragma once

class WindowMain
{
public:
	void Setup();
	void Create();
	void Destroy();
	void Run();

private:
	const int m_x = 0;
	const int m_y = 0;
	const int m_width = 1280;
	const int m_height = 720;
	const char* m_name = "MyWindow\n";

	const int m_color = 0x77777777;

};

