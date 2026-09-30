#pragma once

class Battle
{
public:
	bool BattleMain(Character& allay,Character& enemy);
	bool SceneGuard();
	bool SceneAtk();
public:
	bool m_isAllayTurn{ true };
};
