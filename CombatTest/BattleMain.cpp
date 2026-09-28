#include "Dice.h"
#include "Character.h"
#include "BattleMain.h"

bool BattleMain(Character& allay, Character& enemy)
{
	bool allayTurn{true};

	if (allayTurn)
	{
		int atk = allay.Attack();
	}
	else
	{
		enemy.Attack();
	}

}
