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
	Character* p_attacker{};
	Character* p_defender{};

	while (true)
	{
		if (m_isAllayTurn)
		{
			p_attacker = m_playerP;
			p_defender = m_enemyP;
		}
		else
		{
			p_attacker = m_enemyP;
			p_defender = m_playerP;
		}

		SceneAtk();

		SceneDefence();



	}
	return true;
}

bool Battle::SceneGuard()
{
	return false;
}

bool Battle::SceneAtk()
{
	return false;
}
