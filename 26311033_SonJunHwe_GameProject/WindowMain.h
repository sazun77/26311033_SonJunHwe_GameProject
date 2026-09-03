#pragma once

class WindowMain
{
public:
	void Setup();
	void Create();
	void Destroy();
	void Run();

private:
	const int x = 0;
	const int y = 0;
	const int width = 1280;
	const int height = 720;
	const char* name = "MyTinyMarvelousWindow";

	const int color = 0x77777777;

};

