#include "Stats.h"
#include "Random.h"
#include <iostream>
using namespace std;

Stats::Stats(int hp, int attack, int defence, int speed)
	: _hp(hp), _maxHp(hp), _attack(attack), _defence(defence), _speed(speed)
{
	_random = new Random();
}

Stats::~Stats()
{
	if (_random)
		delete _random;
}

int Stats::SetHp(int hp)
{
	_hp += hp;
	if (_hp < 0)
		_hp = 0;

	return _hp;
}

int Stats::SetMaxHp(int maxHp)
{
	_maxHp += maxHp;
	if (_maxHp < 0)
		_maxHp = 0;

	return _maxHp;
}

int Stats::SetAttack(int attack)
{
	_attack += attack;
	if (_attack < 0)
		_attack = 0;

	return _attack;
};

int Stats::SetDefence(int defence)
{
	_defence += defence;
	if (_defence < 0)
		_defence = 0;

	return _defence;
};

int Stats::SetSpeed(int speed)
{
	_speed += speed;
	if (_speed < 0)
		_speed = 0;

	return _speed;
};

void Stats::LevelUp()
{
	cout << endl;

	_maxHp += _random->GetRandomValue(10, 30);
	_hp = _maxHp;

	PrintStat();

	_attack += _random->GetRandomValue(3, 6);
	_defence += _random->GetRandomValue(3, 6);
	_speed += _random->GetRandomValue(3, 6);

	PrintStat();
};

void Stats::PrintStat()
{
	cout << "[½ºÅÈ]" << endl;
	cout << "HP: " << _hp << endl;
	cout << "Attack: " << _attack << endl;
	cout << "Defence: " << _defence << endl;
	cout << "Speed: " << _speed << endl;
}