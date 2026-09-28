#include <random>
#include "Dice.h"
#include "Character.h"

void Dice::DiceSetup()
{
	std::random_device rd;
	m_mt.seed(rd());
}

int Dice::DiceRoll(DICE dRank)
{
	std::uniform_int_distribution<int> dice(1, dRank);
	return dice(m_mt);
}
