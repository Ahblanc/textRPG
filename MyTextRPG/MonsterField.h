#pragma once
#include "Field.h"

class Player;
class Monster;
class Random;

class MonsterField : public Field
{
public:
	MonsterField();
	virtual ~MonsterField();

	void Init(Player* player);
	int SelectChoice();
	void CreateMonster(Player* player);
	void StartBattle(Player* player);

private:
	Monster* _monster;
	Random* _random;
};

