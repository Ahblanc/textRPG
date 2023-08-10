#include "Game.h"
#include "Player.h"
#include "MonsterField.h"
#include "TreasuresField.h"
#include "Random.h"
#include <iostream>
using namespace std;

Game::Game() : _player(nullptr), _field(nullptr), _random(new Random())
{

}

Game::~Game()
{
	if (_player != nullptr)
		delete _player;

	if (_field != nullptr)
		delete _field;
}

void Game::Init()
{
	_player = new Player();
	_player->PrintInfo();
}

void Game::Update()
{
	if (_player == nullptr)
		Init();

	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		Init();
	}

	int fieldType = _random->GetRandomValue(0, 1);
	switch (fieldType)
	{
	case FT_Monster:
		_field = new MonsterField();
		static_cast<MonsterField*>(_field)->Init(_player);
		
		while (true)
		{
			int choice = static_cast<MonsterField*>(_field)->SelectChoice();

			if (choice == 1)
			{
				static_cast<MonsterField*>(_field)->StartBattle(_player);
				break;
			}
			else if (choice == 2)
			{
				_player->PrintInfo();
			}
			else if (choice == 3)
			{
				cout << "¼º°øÀûÀ¸·Î µµ¸ÁÃÆ´Ù." << endl;
				break;
			}
		}
		break;

	case FT_Treasure:
		_field = new TreasuresField();
		static_cast<TreasuresField*>(_field)->Init();

		while (true)
		{
			int choice = static_cast<TreasuresField*>(_field)->SelectChoice();

			if (choice == 1)
			{
				static_cast<TreasuresField*>(_field)->TreasuresOpen(1, _player);
				break;
			}
			else if (choice == 2)
			{
				static_cast<TreasuresField*>(_field)->TreasuresOpen(2, _player);
				break;
			}
			else if (choice == 3)
			{
				static_cast<TreasuresField*>(_field)->TreasuresOpen(3, _player);
				break;
			}
		}
		break;

	case FT_NPC:
		break;
	}

	delete _field;
}