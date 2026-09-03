#include "WindowMain.h"

int main()
{
    WindowMain window{};

    window.Setup();
    window.Create();
    window.Run();
    window.Destroy();
}

