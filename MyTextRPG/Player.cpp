#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

string GetStateString(int state)
{
	string str = "";

	switch (state)
	{
	case ST_NONE:
		str = "보통";
		break;

	case ST_BlESSING:
		str = "축복";
		break;

	case ST_CURSE:
		str = "저주";
		break;
	}

	return str;
}

void Player::PrintInfo()
{
	cout << endl;
	cout << "[플레이어 정보]" << endl;
	cout << "레벨: " << GetLevel() << endl;
	cout << "경험치: " << GetExp() << endl;
	cout << "특성: " << endl;
	cout << "상태: " << GetStateString(_state) << endl;
	GetStats()->PrintStat();
	cout << endl;
}

void Player::PrintDie()
{
	cout << "************************************************************" << endl;
	cout << "*******************플레이어가 죽었습니다.*******************" << endl;
	cout << "************************************************************" << endl;
}

void Player::PrintExp()
{
	cout << fixed;
	cout.precision(3);

	float exp = static_cast<float>(_exp) / _maxExp * 100;
	cout << "경험치(%): " << exp << endl;
}

void Player::LevelUp(int exp)
{
	int level = GetLevel();
	cout << "레벨업 " << level << " >> " << level + 1 << endl;
	SetLevel(level + 1);
	GetStats()->LevelUp();
	_maxExp = _maxExp * 1.5;
	_exp = abs(exp - _exp);
}

void Player::SetExp(Creature* monster)
{
	int levelGap = (monster->GetLevel() - GetLevel()) / 2;
	if (levelGap < 1)
		levelGap = 1;

	int exp = levelGap * static_cast<Monster*>(monster)->GetMonsterType();

	cout << "경험치 획득( " << exp << " )" << endl;

	if (_maxExp <= _exp + exp)
	{
		LevelUp(exp);
	}
	else
	{
		_exp += exp;
	}

	PrintExp();
}

void Player::SetState(int stateType)
{
	_state = stateType;

	switch (stateType)
	{
	case ST_BlESSING:
		GetStats()->SetAttack(5);
		GetStats()->SetDefence(5);
		GetStats()->SetSpeed(5);
		GetStats()->SetMaxHp(30);
		break;

	case ST_CURSE:
		GetStats()->SetAttack(-3);
		GetStats()->SetDefence(-3);
		GetStats()->SetSpeed(-3);
		GetStats()->SetMaxHp(20);
		break;
	}
}
