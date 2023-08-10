#pragma once

#include "Stats.h"

enum class CreatureType
{
	Player,
	NPC,
	Monster
};

class Creature
{
public:
	Creature(CreatureType, int, int, int, int, int);
	virtual ~Creature() {
		if (_stats)
			delete _stats;
	};


	int GetLevel() { return _level; };
	void SetLevel(int);
	Stats* GetStats() {
		if (_stats)
			return _stats;
	}
	CreatureType GetCreatureType();

	virtual void PrintInfo() = 0;
	virtual void PrintDie() = 0;

	void OnAttacked(Creature*);
	bool IsDamageSame(Creature*);
	bool IsFast(Creature*);
	void PrintCreatureType();
	void PrintCreatureTypeAttack();
	bool IsDead();

private:
	CreatureType _creatureType;
	Stats* _stats;
	int _level = 1;
};