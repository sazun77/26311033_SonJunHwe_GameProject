#include <iostream>
#include "WindowMain.h"
WindowMain window{};

int main()
{
    std::cout << "window setup\n";
    window.Setup();

    std::cout << "window run\n";
    window.Run();

    std::cout << "window destroy\n";
    window.Destroy();
}

