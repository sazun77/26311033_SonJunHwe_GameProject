#include "Dice.h"
#include "Character.h"
#include "Battle.h"

bool Battle::BattleMain(Character& allay, Character& enemy)
{
	if (m_isAllayTurn)
	{
		int atk = allay.Attack();
	}
	else
	{
		int atk = enemy.Attack();
	}

	return true;
}
