#include <iostream>
#include "Dice.h"
#include "Character.h"

void Character::SetSetupStandard(std::string name ,Dice* diceP)
{
	m_name = name;
	m_diceP = diceP;

	m_atk = m_diceP->DiceRoll(DR_4TETRAHEDRON) - DR_4TETRAHEDRON/2;
	m_def = m_diceP->DiceRoll(DR_4TETRAHEDRON) - DR_4TETRAHEDRON / 2;
	m_dex = m_diceP->DiceRoll(DR_4TETRAHEDRON) - DR_4TETRAHEDRON / 2;
}

bool Character::SetHp(int damage)
{
	m_hpCurrent -= damage;

	if (0>m_hpCurrent)
	{
		m_hpCurrent = 0;
	}
	else if (m_hpMax < m_hpCurrent)
	{
		m_hpCurrent = m_hpMax;
	}

	if (0 == m_hpCurrent)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Character::ShowName()
{
	std::cout << m_name << '\n';
}

void Character::ShowHp()
{
	std::cout << "HP : " << m_hpCurrent << '/' << m_hpMax << '\n';
}

void Character::ShowStatus()
{
	std::cout << "Atk : " << std::showpos << m_atk << std::noshowpos << '\n';
	std::cout << "Def : " << std::showpos << m_def << std::noshowpos << '\n';
	std::cout << "Dex : " << std::showpos << m_dex << std::noshowpos << '\n';
}

int Character::Attack()
{
	return m_atk + m_diceP->DiceRoll(DR_20ICOSAHEDRON);
}

int Character::Guard()
{
	return m_def + m_diceP->DiceRoll(DR_20ICOSAHEDRON);
}

int Character::Avoid()
{
	return m_dex + m_diceP->DiceRoll(DR_20ICOSAHEDRON);
}

std::string Character::GetName()
{
	return m_name;
}

int Character::GetHpMax()
{
	return m_hpMax;
}

int Character::GetHpCurrent()
{
	return m_hpCurrent;
}

int Character::GetAtk()
{
	return m_atk;
}

int Character::GetDef()
{
	return m_def;
}

int Character::GetDex()
{
	return m_dex;
}

