#include <iostream>
#include <Windows.h>
#include "Dice.h"
#include "Character.h"
#include "Battle.h"

int main()
{
	// 콘솔 창 위치 및 크기 설정
	HWND hConsole = GetConsoleWindow();

	// X, Y, 가로, 세로
	MoveWindow(hConsole, 0, 0, GetSystemMetrics(SM_CXSCREEN)/2, GetSystemMetrics(SM_CYSCREEN) / 2, TRUE);

	Dice dice{};
	dice.DiceSetup();

	Character player{};
	Character enemy{};
	player.SetSetupStandard("Player", & dice);
	enemy.SetSetupStandard("Enemy", & dice);

	Battle battleMain{};
	battleMain.Setup(&player, &enemy);

	battleMain.BattleMain();
}