#pragma once
#include "Creature.h"

enum StateType
{
	ST_NONE,
	ST_BlESSING,
	ST_CURSE
};

enum class PropertyType
{
	NONE,
	BERSERKER
};

class Player : public Creature
{
public:
	Player() : Creature(CreatureType::Player, 200, 15, 15, 15, 1)	{};
	~Player() {};
	
	void PrintInfo();
	void PrintDie();
	float GetExp() { return static_cast<float>(_exp) / _maxExp * 100; };
	void PrintExp();
	void LevelUp(int);
	void SetExp(Creature*);
	void SetState(int);

private:
	int _exp = 0;
	int _maxExp = 16;
	int _state = ST_NONE;
	PropertyType _property = PropertyType::NONE;
};