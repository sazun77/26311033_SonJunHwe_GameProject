#pragma once

class Battle
{
public:

	void Setup(Character* player, Character* enemy);
	
	bool BattleMain();
	void SceneBroadCast();

		void SceneSetTurn(Character** attackerPP, Character** defenderPP);
		
		int SceneAtk(Character* attackerP);
		
		COMMAND SceneDefence(Character* defenderP, int powerAtk);//isAlive return
			int SceneGuard(Character* defenderP, int powerAtk);	// 공격 위력 - 수비 위력 반환.
			bool SceneAvoid(Character* defenderP, int powerAtk);	// 회피 성공 여부 리턴.
		bool SceneDamageStep(Character* attackerP, Character* defenderP, COMMAND inputCommand, int powerAtk);
public:
	bool m_isAllayTurn{ true };
	Character* m_playerP{};
	Character* m_enemyP{};
};
