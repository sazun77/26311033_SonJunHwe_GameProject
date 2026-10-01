#include "Dice.h"
#include "Character.h"

void Character::SetSetupStandard(std::string name ,Dice* diceP)
{
	m_name = name;
	m_diceP = diceP;

	m_atk = m_diceP->DiceRoll(DR_4TETRAHEDRON);
	m_def = m_diceP->DiceRoll(DR_4TETRAHEDRON);
	m_dex = m_diceP->DiceRoll(DR_4TETRAHEDRON);
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

int Character::GetHpCurrent()
{
	return m_hpCurrent;
}
