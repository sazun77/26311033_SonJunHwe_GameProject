#include "Dice.h"
#include "Character.h"

void Character::SetStandard(Dice* diceP)
{
	m_diceP = diceP;

	m_atk = m_diceP->DiceRoll(DR_4TETRAHEDRON);
	m_def = m_diceP->DiceRoll(DR_4TETRAHEDRON);
	m_dex = m_diceP->DiceRoll(DR_4TETRAHEDRON);
}

void Character::SetHp(int damage)
{
	m_hp -= damage;

	if (0>m_hp)
	{
		m_hp = 0;
	}
}

int Character::Attack()
{
	return m_atk + m_diceP->DiceRoll(DR_20ICOSAHEDRON);
}

int Character::Guard(int enemyAtk)
{
	int defence = m_def + m_diceP->DiceRoll(DR_20ICOSAHEDRON);
	int damage = enemyAtk - defence;
	if (damage < CHARACTER_GUARD_DMG_MIN)
	{
		damage = CHARACTER_GUARD_DMG_MIN;
	}

	return damage;
}

int Character::Avoid(int enemyAtk)
{
	return m_dex + m_diceP->DiceRoll(DR_20ICOSAHEDRON);
}
