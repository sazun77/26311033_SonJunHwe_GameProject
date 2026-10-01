#include <iostream>
#include "Dice.h"
#include "Character.h"

int main()
{
	Dice dice{};
	dice.DiceSetup();

	Character player{};
	Character enemy{};
	player.SetSetupStandard("Player", & dice);
	enemy.SetSetupStandard("Enemy", & dice);


}