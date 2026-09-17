#include <iostream>
#include "WindowMain.h"
#include "Constants.h"
#include "SoundEffectter.h"

WindowMain window{};
SoundEffectter testSound{};

int main()
{
    std::cout << "window setup\n";
    window.Setup();

    // image set
    int imageDoro = window.SetImageNew(DORO);
    int imageAtk = window.SetImageNew(ICON_ATK);
    int imageDef = window.SetImageNew(ICON_DEF);
    int imageAvoid = window.SetImageNew(ICON_AVOID);
    window.SetImagePos(imageAtk, 0, window.GetHeight() - window.GetImageHeight(imageAtk));
    window.SetImagePos(imageDef,window.GetImageX(imageAtk)+ window.GetImageWidth(imageDef),window.GetImageY(imageAtk));
    window.SetImagePos(imageAvoid, window.GetImageX(imageDef) + window.GetImageWidth(imageAvoid), window.GetImageY(imageAtk));

    // sound setting
    testSound.SetIdx(SOUNDTEST);

    std::cout << "window run\n";
    window.Run();

    std::cout << "window destroy\n";
    window.Destroy();
}
