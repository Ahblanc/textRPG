#include "TreasuresField.h"
#include "Treasures.h"
#include <iostream>
#include <string>
using namespace std;

TreasuresField::TreasuresField()
{
	_fieldType = FT_Treasure;
	_treasures1 = new Treasures();
	_treasures2 = new Treasures();
	_treasures3 = new Treasures();
}

TreasuresField::~TreasuresField()
{
	if (_treasures1)
		delete _treasures1;

	if (_treasures2)
		delete _treasures2;

	if (_treasures3)
		delete _treasures3;
}

void TreasuresField::Init()
{
	cout << "보물상자 3개가 등장했다." << endl;
	cout << endl;
}

int TreasuresField::SelectChoice()
{
	string choice = "";

	while (true)
	{
		cout << endl;
		cout << "[보물을 선택해주세요.]" << endl;
		cout << "[1번 보물]" << endl;
		cout << "[2번 보물]" << endl;
		cout << "[3번 보물]" << endl;
		cout << endl;
		cout << ">> ";
		cin >> choice;

		if (choice == "1" || choice == "2" || choice == "3")
			break;
	}

	return stoi(choice);
}

void TreasuresField::TreasuresOpen(int num, Player* player)
{

	switch (num)
	{
	case 1:
		_treasures1->Open(player);
		break;

	case 2:
		_treasures2->Open(player);
		break;

	case 3:
		_treasures3->Open(player);
		break;
	}
}


