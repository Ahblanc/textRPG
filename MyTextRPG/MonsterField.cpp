#include "MonsterField.h"
#include "Monster.h"
#include "Player.h"
#include "Random.h"
#include <iostream>
#include <string>
using namespace std;

MonsterField::MonsterField() : _monster(nullptr)
{
	_fieldType = FT_Monster;
	_random = new Random();
}

MonsterField::~MonsterField()
{
	if (_monster != nullptr)
		delete _monster;

	if (_random != nullptr)
		delete _random;
}

void MonsterField::Init(Player* player)
{
	if (_monster == nullptr)
		CreateMonster(player);

	_monster->PrintInfo();

	cout << "몬스터가 등장했다." << endl;
	cout << endl;
}

int MonsterField::SelectChoice()
{
	string choice = "";

	while (true)
	{
		cout << endl;
		cout << "[행동을 선택해주세요.]" << endl;
		cout << "[1. 전투]" << endl;
		cout << "[2. Player 정보]" << endl;
		cout << "[3. 도망]" << endl;
		cout << endl;
		cout << ">> ";
		cin >> choice;

		if (choice == "1" || choice == "2" || choice == "3")
			break;
	}

	return stoi(choice);
}

void MonsterField::CreateMonster(Player* player)
{
	int level = player->GetLevel() + _random->GetRandomValue(-3, 3);
	if (level < 1)
		level = 1;

	switch (_random->GetRandomValue(0, 6)) // TODO: 확률을 지수 함수 확률로 변경.
	{
	case MT_Slime:
		_monster = new Slime(level);
		break;
	case MT_Goblin:
		_monster = new Goblin(level);
		break;
	case MT_GoldGoblin:
		_monster = new GoldGoblin(level);
		break;
	case MT_Skeleton:
		_monster = new Skeleton(level);
		break;
	case MT_Orc:
		_monster = new Orc(level);
		break;
	case MT_Orge:
		_monster = new Orge(level);
		break;
	case MT_Bandit:
		_monster = new Bandit(level);
		break;
	}
}

void MonsterField::StartBattle(Player* player)
{
	cout << endl;

	if (player->IsDamageSame(_monster))
	{
		cout << "몬스터가 화들짝 놀라 도망쳤다." << endl;
		return;
	}

	cout << "[전투 시작]" << endl;

	Creature* first = player;
	Creature* second = _monster;

	if (player->IsFast(_monster))
	{
		first = _monster;
		second = player;
	}

	while (true)
	{
		first->PrintCreatureTypeAttack();
		second->OnAttacked(first);

		if (second->IsDead())
		{
			second->PrintDie();

			if (second->GetCreatureType() == CreatureType::Monster)
			{
				player->SetExp(_monster);

				delete _monster;
				_monster = nullptr;
			}

			first = nullptr;
			second = nullptr;
			break;
		}

		second->PrintCreatureTypeAttack();
		first->OnAttacked(second);

		if (first->IsDead())
		{
			first->PrintDie();

			if (first->GetCreatureType() == CreatureType::Monster)
			{
				player->SetExp(_monster);

				delete _monster;
				_monster = nullptr;
			}

			first = nullptr;
			second = nullptr;
			break;
		}
	}

	cout << "[전투 종료]" << endl;
	cout << endl;
}