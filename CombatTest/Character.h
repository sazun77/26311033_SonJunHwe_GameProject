#pragma once
#include "Dice.h"

enum ENUM_CHARACTER
{
	CHARACTER_HP = 100,
	CHARACTER_GUARD_POWER_MIN = 1,
};

typedef enum COMMAND
{
	GUARD = 1,
	AVOID =2,
	COUNTERATTACK=3,
}COMMAND;

class Character
{
public:

	void SetSetupStandard(std::string name, Dice* diceP);
	bool SetHp(int damage = 0);

	std::string GetName();
	int GetHpMax();
	int GetHpCurrent();
	int GetAtk();
	int GetDef();
	int GetDex();

	void ShowName();
	void ShowHp();
	void ShowStatus();

	int Attack();
	int Guard();
	int Avoid();
private:
	int m_hpMax{ CHARACTER_HP };
	int m_hpCurrent{ CHARACTER_HP };
	int m_atk{};
	int m_def{};
	int m_dex{};

	std::string m_name{};
	Dice* m_diceP{};
};
