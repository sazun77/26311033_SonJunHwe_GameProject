#include "Dice.h"
#include "Character.h"
#include "Battle.h"

void Battle::Setup(Character* player, Character* enemy)
{
	m_playerP = player;
	m_enemyP = enemy;
}

bool Battle::BattleMain()
{
	Character* attackerP{};
	Character* defenderP{};

	while (true)
	{
		SceneSetTurn(&attackerP, &defenderP);

		int powerAttack = SceneAtk(attackerP);

		SceneDefence(defenderP, powerAttack);



	}
	return true;
}

void Battle::SceneSetTurn(Character** attackerPP, Character** defenderPP)
{
	if (m_isAllayTurn)
	{
		*attackerPP = m_playerP;
		*defenderPP = m_enemyP;
	}
	else
	{
		*attackerPP = m_enemyP;
		*defenderPP = m_playerP;
	}
}

int Battle::SceneGuard(Character* defenderP, int powerAtk)
{
	int powerFine = powerAtk - defenderP->Guard();
	
	if (powerFine < CHARACTER_GUARD_DMG_MIN)
	{
		powerFine = CHARACTER_GUARD_DMG_MIN;
	}

	return powerFine;
}
