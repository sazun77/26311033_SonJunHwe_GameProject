#include <iostream>
#include "WindowMain.h"

WindowMain window{};

int main()
{
    std::cout << "window setup\n";
    window.Setup();

    int imageDoro = window.SetImageNew("Textures/tst.png");
    int imageAtk = window.SetImageNew("Textures/Icon_Atk.png");
    int imageDef = window.SetImageNew("Textures/Icon_Def.png");
    int imageAvoid = window.SetImageNew("Textures/Icon_Avoid.png");
    // window.GetImageWidth(imageAtk)
    window.SetImagePos(imageAtk, 0, window.GetHeight() - window.GetImageHeight(imageAtk));
    window.SetImagePos(imageDef,window.GetImageX(imageAtk)+ window.GetImageWidth(imageDef),window.GetImageY(imageAtk));
    window.SetImagePos(imageAvoid, window.GetImageX(imageDef) + window.GetImageWidth(imageAvoid), window.GetImageY(imageAtk));

    std::cout << "window run\n";
    window.Run();

    std::cout << "window destroy\n";
    window.Destroy();
}
