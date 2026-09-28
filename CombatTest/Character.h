#pragma once
#include "Dice.h"

class Character
{
public:
	int StandardSet(DICE dRank = TWENTY);

	int Attack();
	int Guard(int enemyAtk);
	int Avoid(int enemyAtk);
private:
	int m_hp{100};
	int m_atk{};
	int m_def{};
	int m_dex{};

	DICE m_diceRank{};
};