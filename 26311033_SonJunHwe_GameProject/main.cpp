#include <iostream>
#include <Windows.h>

#include "Battle/Dice.h"
#include "Battle/Character.h"
#include "Battle/Battle.h"
#include "WindowMain.h"
#include "Constants.h"
#include "SoundEffectter.h"

WindowMain window{};
SoundEffectter testSound{};

int main()
{
    std::cout << "window setup\n";
    window.Setup();

    // 콘솔 창 위치 및 크기 설정
    HWND hConsole = GetConsoleWindow();
    MoveWindow(hConsole, 0, 0, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2, TRUE);
    // 랜덤 설정.
    Dice dice{};
    dice.DiceSetup();
    // 플레이어, 적 설정.
    Character player{};
    Character enemy{};
    player.SetSetupStandard("Player", &dice, 3);
    enemy.SetSetupStandard("Enemy", &dice, 3);

    Battle battleMain{};
    battleMain.Setup(&player, &enemy);
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
