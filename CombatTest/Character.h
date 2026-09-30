#pragma once
#include "Dice.h"

enum ENUM_CHARACTER
{
	CHARACTER_HP = 100,
	CHARACTER_GUARD_DMG_MIN = 1,
};

typedef enum COMMAND
{
	GUARD = 1,
	AVOID =2,
	COUNTERATTACK=3,
};

class Character
{
public:

	void SetStandard(Dice* diceP);
	void SetHp(int damage = 0);
	int Attack();
	int Guard();
	int Avoid();

private:
	int m_hpMax{ CHARACTER_HP };
	int m_hpCurrent{ CHARACTER_HP };
	int m_atk{};
	int m_def{};
	int m_dex{};

	Dice* m_diceP{};
};
