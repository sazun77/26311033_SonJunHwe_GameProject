#pragma once
#include <random>

typedef enum DICE
{
	SQUARE = 4,
	SIX = 6,
	EIGHT = 8,
	TWENTY = 20,
}DICE;

class Dice
{
public:
	void DiceSetup();
	int DiceRoll(DICE dRank);
private:
	std::mt19937 m_mt{};
};