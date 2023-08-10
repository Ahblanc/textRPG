#include "Creature.h"
#include <iostream>
using namespace std;

string GetCreatureTypeString(CreatureType ct)
{
	string creatureString = "";

	if (ct == CreatureType::Player)
		creatureString = "Player";
	else if (ct == CreatureType::NPC)
		creatureString = "NPC";
	else if (ct == CreatureType::Monster)
		creatureString = "Monster";

	return creatureString;
}

Creature::Creature(CreatureType ct, int hp, int attack, int defence, int speed, int level)
{
	_creatureType = ct;
	_stats = new Stats(hp, attack, defence, speed);
	_level = level;
};

void Creature::SetLevel(int level)
{
	_level = level;
}

CreatureType Creature::GetCreatureType()
{
	return _creatureType;
}

void Creature::OnAttacked(Creature* attacker)
{
	int damage = attacker->_stats->GetAttack() - _stats->GetDefence();
	if (damage < 0)
		damage = 0;

	cout << "데미지 : " << damage << endl;
	cout << "남은 체력 : " << _stats->SetHp(-damage) << endl;
}

bool Creature::IsDamageSame(Creature* attacker)
{
	bool result = false;

	int damage1 = attacker->_stats->GetAttack() - _stats->GetDefence();
	if (damage1 < 0)
		damage1 = 0;

	int damage2 = _stats->GetAttack() - attacker->_stats->GetDefence();
	if (damage2 < 0)
		damage2 = 0;

	if (damage1 == 0 && damage2 == 0)
		result = true;
	
	return false;
}

bool Creature::IsFast(Creature* attacker)
{
	bool result = false;

	if (attacker->GetStats()->GetSpeed() >= _stats->GetSpeed()) 
		result = true;

	// false는 자신이 빠름.
	// true는 attacker가 빠름.
	return result;
}

void Creature::PrintCreatureType()
{
	string creatureString = GetCreatureTypeString(_creatureType);
	cout << creatureString;
}

void Creature::PrintCreatureTypeAttack()
{
	string creatureString = GetCreatureTypeString(_creatureType);
	cout << creatureString << "의 공격" << endl;
}

bool Creature::IsDead()
{
	return _stats->GetHp() <= 0;
}