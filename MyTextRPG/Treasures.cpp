#include "Treasures.h"
#include "Player.h"
#include "Random.h"
#include <iostream>
using namespace std;

Treasures::Treasures()
{
	_random = new Random();
	_contentType = _random->GetRandomValue(0, 3);
	_itemType = _random->GetRandomValue(0, 8);
	_stateType = _random->GetRandomValue(0, 3);
}

Treasures::~Treasures()
{
	if (_random)
		delete _random;
}

void Treasures::Open(Player* player)
{
	cout << endl;
	cout << "보물상자를 연다..." << endl;

	switch (_contentType)
	{
	case C_None:
		cout << "꽝!!!!!!!!!!" << endl;
		break;

	case C_Item:
		switch (_itemType)
		{
		case IC_None:
			cout << "꽝!!!!!!!!!!" << endl;
			break;

		case IC_Sword:
			cout << "검을 얻었다." << endl;
			cout << "Attack +5" << endl;
			player->GetStats()->SetAttack(5);
			player->PrintInfo();
			break;

		case IC_Armor:
			cout << "갑옷을 얻었다." << endl;
			cout << "Defence +5" << endl;
			player->GetStats()->SetDefence(5);
			player->PrintInfo();
			break;

		case IC_Shoes:
			cout << "신발을 얻었다." << endl;
			cout << "Speed +5" << endl;
			player->GetStats()->SetSpeed(5);
			player->PrintInfo();
			break;

		case IC_Potion:
			cout << "포션을 얻었다." << endl;
			cout << "Hp +30" << endl;
			player->GetStats()->SetMaxHp(30);
			player->PrintInfo();
			break;

		case IC_CurseSword:
			cout << "저주받은 검을 얻었다." << endl;
			cout << "Attack -3" << endl;
			player->GetStats()->SetAttack(-3);
			player->PrintInfo();
			break;

		case IC_CurseArmor:
			cout << "저주받은 값옷을 얻었다." << endl;
			cout << "Defence -3" << endl;
			player->GetStats()->SetDefence(-3);
			player->PrintInfo();
			break;

		case IC_CurseShoes:
			cout << "저주받은 신발을 얻었다." << endl;
			cout << "Speed -3" << endl;
			player->GetStats()->SetSpeed(-3);
			player->PrintInfo();
			break;

		case IC_CursePotion:
			cout << "저주받은 포션을 얻었다." << endl;
			cout << "Hp -20" << endl;
			player->GetStats()->SetMaxHp(-20);
			player->PrintInfo();
			break;
		}
		break;

	case C_State:
		switch (_stateType)
		{
		case SC_None:
			cout << "꽝!!!!!!!!!!" << endl;
			break;

		case SC_Blessing:
			cout << "축복을 받았다." << endl;
			cout << "Hp +30" << endl;
			cout << "Attack +5" << endl;
			cout << "Defence +5" << endl;
			cout << "Speed +5" << endl;
			player->SetState(SC_Blessing);
			player->PrintInfo();
			break;

		case SC_Curse:
			cout << "저주에 걸렸다." << endl;
			cout << "Hp -20" << endl;
			cout << "Attack -3" << endl;
			cout << "Defence -3" << endl;
			cout << "Speed -3" << endl;
			player->SetState(SC_Curse);
			player->PrintInfo();
			break;
		}
		break;
	}
}
