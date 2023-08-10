#pragma once

class Random;

class Stats
{
public:
	Stats(int hp, int attack, int defence, int speed);
	~Stats();

	int GetHp() { return _hp; };
	int GetAttack() { return _attack; };
	int GetDefence() { return _defence; };
	int GetSpeed() { return _speed; };
	int SetHp(int);
	int SetMaxHp(int);
	int SetAttack(int);
	int SetDefence(int);
	int SetSpeed(int);
	void LevelUp();
	void PrintStat();

private:
	int _hp = 0;
	int _maxHp = 0;
	int _attack = 0;
	int _defence = 0;
	int _speed = 0;
	Random* _random;
};