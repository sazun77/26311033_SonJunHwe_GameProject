#pragma once

class Battle
{
public:

	void Setup(Character* player, Character* enemy);
	bool BattleMain();

	bool SceneAtk();
	bool SceneDefence();
	bool SceneGuard();
	bool SceneAvoid();
public:
	bool m_isAllayTurn{ true };
	Character* m_playerP{};
	Character* m_enemyP{};
};
