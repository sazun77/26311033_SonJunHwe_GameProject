#include <iostream>
#include "MyHeader.h"
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

		COMMAND inputCommand{ SceneDefence(defenderP, powerAttack) };
		
		bool isDefenderAlive = SceneDamageStep(attackerP, defenderP, inputCommand, powerAttack);

		if (!isDefenderAlive)
		{
			break;
		}
	}

	if (0 == m_playerP->GetHpCurrent())
	{
		Messege("You lose...\n");
		return true;

	}
	else
	{
		Messege("You win!\n");
		return false;

	}
}

void Battle::SceneSetTurn(Character** attackerPP, Character** defenderPP)
{
	if (m_isAllayTurn)
	{
		Messege("your turn\n");
		*attackerPP = m_playerP;
		*defenderPP = m_enemyP;
	}
	else
	{
		Messege("Enemy turn\n");
		*attackerPP = m_enemyP;
		*defenderPP = m_playerP;
	}
}

int Battle::SceneAtk(Character* attackerP)
{
	int powerAttack{ attackerP->Attack() };

	std::cout << "attack power : " << powerAttack << '\n';

	return powerAttack;
}

COMMAND Battle::SceneDefence(Character* defenderP, int powerAtk)
{
	while(true)
	{
		Messege("Chose deffence type.\n");
		std::cout << GUARD << " : guard\n";
		std::cout << AVOID << " : avoid\n";

		COMMAND inputCommand = static_cast<COMMAND>(InputInt());

		switch (inputCommand)
		{
		case(GUARD):
		{
			return GUARD;
		}
		case(AVOID):
		{
			return AVOID;
		}
		default:
		{
			Messege("Wrong input, please try again\n");
			continue;
		}
		}
	}
}

int Battle::SceneGuard(Character* defenderP, int powerAtk)
{
	int powerGuard{ defenderP->Guard() };
	int powerFine = powerAtk - powerGuard;
	
	std::cout << "Guard power : " << powerGuard << '\n';
	if (powerFine < CHARACTER_GUARD_POWER_MIN)
	{
		Messege("Minimum damage!\n");
		powerFine = CHARACTER_GUARD_POWER_MIN;
	}

	return powerFine;
}

bool Battle::SceneAvoid(Character* defenderP, int powerAtk)
{
	int powerAvoid{ defenderP->Avoid() };

	std::cout << "Avoid power : " << powerAvoid << '\n';
	if (powerAvoid >= powerAtk)
	{
		Messege("Avoid success!\n");
		return true;
	}
	else
	{
		Messege("Avoid Failed...\n");
		return false;
	}
}

bool Battle::SceneDamageStep(Character* attackerP, Character* defenderP,COMMAND inputCommand,int powerAtk)
{
	int powerFine{};
	switch (inputCommand)
	{
	case(GUARD):
	{
		powerFine = SceneGuard(defenderP, powerAtk);
	}
	case(AVOID):
	{
		bool isAvoided{ SceneAvoid(defenderP,powerAtk) };

		if (isAvoided)
		{
			return true;
		}
	}
	}

	// 여기에 만약에 피해량 증감 있다면 그거 적용.
	// 다만 아직은 그런 수준으로 만들지는 않음.
	// ...
	int damageFine{powerFine};

	std::cout << attackerP->GetName() << " injured " << damageFine << " to " << defenderP->GetName() << '\n';

	bool isAlive{ defenderP->SetHp(powerFine) };

	if (isAlive)
	{
		return true;
	}
	else
	{
		std::cout << defenderP->GetName() << " is dead.\n";
		return false;
	}
}
