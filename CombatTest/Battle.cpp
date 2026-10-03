#include <iostream>
#include "MyHeader.h"
#include "Dice.h"
#include "Character.h"
#include "Battle.h"

using std::cout;

void Battle::Setup(Character* player, Character* enemy)
{
	m_playerP = player;
	m_enemyP = enemy;
}

bool Battle::BattleMain()
{
	Character* attackerP{};
	Character* defenderP{};
	unsigned int round{};

	m_playerP->ShowName();
	m_playerP->ShowStatus();
	Messege("\n");
	m_enemyP->ShowName();
	m_enemyP->ShowStatus();
	Messege("battle start\n");
	Messege("=====\n");

	while (true)
	{
		SceneBroadCast(++round);
		cout << '\n';

		SceneSetTurn(&attackerP, &defenderP); 
		cout << '\n';

		int powerAttack = SceneAtk(attackerP);
		//ToNext();

		COMMAND inputCommand{ SceneDefence(defenderP,powerAttack) }; 

		bool isDefenderAlive = SceneDamageStep(attackerP, defenderP, inputCommand, powerAttack);
		ToNext();

		if (!isDefenderAlive)
		{
			break;
		}

		//InputString("다음으로 진행하려면 확인을 눌러주세요.\n");
		Messege("=======\n");
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

void Battle::SceneBroadCast(const unsigned int round)
{
	std::cout << "round " << round << '\n';

	Character* ptr{ m_playerP };
	ptr->ShowName();
	ptr->ShowHp();

	ptr= m_enemyP;
	ptr->ShowName();
	ptr->ShowHp();
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

	if(m_isAllayTurn)
	{
		InputString("공격하려면 확인을 눌러주세요.");
	}

	std::cout << "attack power : " << powerAttack << '('<<ToSignedNumber(attackerP->GetAtk())<<')' << '\n';

	return powerAttack;
}

COMMAND Battle::SceneDefence(Character* defenderP, int powerAtk)
{
	if (m_isAllayTurn)
	{
		if (powerAtk <= DR_20ICOSAHEDRON / 2)
		{
			std::cout << defenderP->GetName() << " chosed avoid\n";
			return AVOID;
		}
		else
		{
			std::cout << defenderP->GetName() << " chosed guard\n";
			return GUARD;
		}
	}
	else
	{
		Messege("Chose deffence type.\n");
		std::cout << GUARD << " : guard\n";
		std::cout << AVOID << " : avoid\n";

		while (true)
		{
			Messege("Input : ");

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
}

int Battle::SceneGuard(Character* defenderP, int powerAtk)
{
	int powerGuard{ defenderP->Guard() };
	int powerFine = powerAtk - powerGuard;
	
	std::cout << "Guard power : " << powerGuard <<'(' << ToSignedNumber(defenderP->GetDef()) <<')'<< '\n';
	if (powerFine <= CHARACTER_GUARD_POWER_MIN)
	{
		Messege("Minimum damage!\n");
		powerFine = CHARACTER_GUARD_POWER_MIN;
	}

	return powerFine;
}

bool Battle::SceneAvoid(Character* defenderP, int powerAtk)
{
	int powerAvoid{ defenderP->Avoid() };

	std::cout <<"Avoid power : " << powerAvoid <<'('<< ToSignedNumber(defenderP->Avoid()) <<')'<< '\n';
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
	int powerFine{powerAtk};
	switch (inputCommand)
	{
	case(GUARD):
	{
		powerFine = SceneGuard(defenderP, powerAtk);
		break;
	}
	case(AVOID):
	{
		bool isAvoided{ SceneAvoid(defenderP,powerAtk) };

		if (isAvoided)
		{
			m_isAllayTurn = !m_isAllayTurn;
			return true;
		}
		else
		{
			break;
		}
	}
	}

	// 여기에 만약에 피해량 증감 있다면 그거 적용.
	// 다만 아직은 그런 수준으로 만들지는 않음.
	// ...
	int damageFine{powerFine};

	std::cout << attackerP->GetName() << " injured " << damageFine << " to " << defenderP->GetName() << '\n';

	bool isAlive{ defenderP->UpdateHp(powerFine) };

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
