#include <iostream>
#include <Windows.h>
#include "Dice.h"
#include "Character.h"
#include "Battle.h"
/*
int main()
{
	// 콘솔 창 위치 및 크기 설정
	HWND hConsole = GetConsoleWindow();
	MoveWindow(hConsole, 0, 0, GetSystemMetrics(SM_CXSCREEN)/2, GetSystemMetrics(SM_CYSCREEN) / 2, TRUE);
	// 랜덤 설정.
	Dice dice{};
	dice.DiceSetup();
	// 플레이어, 적 설정.
	Character player{};
	Character enemy{};
	player.SetSetupStandard("Player", & dice,3);
	enemy.SetSetupStandard("Enemy", & dice,3);

	Battle battleMain{};
	battleMain.Setup(&player, &enemy);

	battleMain.BattleMain();
}
*/