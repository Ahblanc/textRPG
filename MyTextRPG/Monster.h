#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_Slime,
	MT_Goblin,
	MT_GoldGoblin,
	MT_Skeleton,
	MT_Orc,
	MT_Orge,
	MT_Bandit
};

class Monster : public Creature
{
public:
	Monster(MonsterType monsterType, int hp, int attack, int defence, int speed, int level)
		: Creature(CreatureType::Monster, hp, attack, defence, speed, level) 
	{
		_monsterType = monsterType;
	};
	virtual ~Monster() {};
	void PrintInfo();
	void PrintDie();
	int GetMonsterType() { return _monsterType; };

private:
	MonsterType _monsterType;
};

class Slime : public Monster
{
public:
	Slime(int level)
		: Monster(MT_Slime, 15 + (5 * level), 5 + (1 * level), 5 + (1 * level), 5 + (1 * level), level)
	{

	};
	virtual ~Slime() {};
};

class Goblin : public Monster
{
public:
	Goblin(int level)
		: Monster(MT_Goblin, 30 + (6 * level), 6 + (2 * level), 6 + (2 * level), 6 + (2 * level), level)
	{

	};
	virtual ~Goblin() {};
};

class GoldGoblin : public Monster
{
public:
	GoldGoblin(int level)
		: Monster(MT_GoldGoblin, 40 + (8 * level), 2 + (2 * level), 8 + (2 * level), 7 + (4 * level), level)
	{

	};
	virtual ~GoldGoblin() {};
};

class Skeleton : public Monster
{
public:
	Skeleton(int level)
		: Monster(MT_Skeleton, 50 + (8 * level), 7 + (3 * level), 8 + (2 * level), 5 + (2 * level), level)
	{

	};
	virtual ~Skeleton() {};
};

class Orc : public Monster
{
public:
	Orc(int level)
		: Monster(MT_Orc, 50 + (13 * level), 10 + (3 * level), 9 + (2 * level), 3 + (1 * level), level)
	{

	};
	virtual ~Orc() {};
};

class Orge : public Monster
{
public:
	Orge(int level)
		: Monster(MT_Orge, 80 + (12 * level), 12 + (3 * level), 6 + (2 * level), 2 + (1 * level), level)
	{

	};
	virtual ~Orge() {};
};

class Bandit : public Monster
{
public:
	Bandit(int level)
		: Monster(MT_Bandit, 50 + (5 * level), 9 + (3 * level), 3 + (1 * level), 10 + (3 * level), level)
	{

	};
	virtual ~Bandit() {};
};