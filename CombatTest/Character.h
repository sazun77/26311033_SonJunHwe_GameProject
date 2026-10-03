#pragma once
#include "Dice.h"

enum ENUM_CHARACTER
{
	CHARACTER_HP = 20,
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

	void SetSetupStandard(std::string name, Dice* diceP,int level =1);

	std::string GetName();
	int GetHpMax();
	int GetHpCurrent();
	int GetAtk();
	int GetDef();
	int GetDex();

	void UpdateStatus();
	bool UpdateHp(int damage = 0);
	void UpdateLevel();
	void UpdateExp(int expChange);


	void ShowName();
	void ShowHp();
	void ShowStatus();

	int Attack();
	int Guard();
	int Avoid();
private:
	int m_hpMax{ CHARACTER_HP };
	int m_hpCurrent{ CHARACTER_HP };
	int m_level{1};
	int m_expReqired{};
	int m_exp{};
	int m_atk{};
	int m_def{};
	int m_dex{};

	std::string m_name{};
	Dice* m_diceP{};
	DICERANK m_dr{ DR_6HEXAHEDRON };
};
