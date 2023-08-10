#include "Monster.h"
#include <iostream>
using namespace std;

string GetMonsterTypeString(MonsterType mt)
{
	string monsterString = "";

	switch (mt)
	{
	case MT_Slime:
		monsterString = "Slime";
		break;
	case MT_Goblin:
		monsterString = "Goblin";
		break;
	case MT_GoldGoblin:
		monsterString = "GoldGoblin";
		break;
	case MT_Skeleton:
		monsterString = "Skeleton";
		break;
	case MT_Orc:
		monsterString = "Orc";
		break;
	case MT_Orge:
		monsterString = "Orge";
		break;
	case MT_Bandit:
		monsterString = "Bandit";
		break;
	}

	return monsterString;
}

void Monster::PrintInfo()
{
	cout << endl;
	cout << "[���� ����]" << endl;
	cout << "Ÿ��: " << GetMonsterTypeString(_monsterType) << endl;
	cout << "����: " << GetLevel() << endl;
	GetStats()->PrintStat();
	cout << endl;
}

void Monster::PrintDie()
{
	cout << "���Ͱ� �׾����ϴ�." << endl;
}