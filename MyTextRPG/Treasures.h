#pragma once

class Player;
class Random;

enum Content
{
	C_None,
	C_Item,
	C_State
};

enum ItemContent
{
	IC_None, // ��
	IC_Sword, // ���� ����
	IC_Armor, // ���� ����
	IC_Shoes, // ���ǵ� ����
	IC_Potion, // ü�� ����
	IC_CurseSword, // ���� ����
	IC_CurseArmor, // ���� ����
	IC_CurseShoes, // ���ǵ� ����
	IC_CursePotion, // ü�� ����
};

enum StateContent
{
	SC_None, // ��
	SC_Blessing, // �ູ
	SC_Curse // ����
};

class Treasures
{
public:
	Treasures();
	~Treasures();

	void Open(Player*);

private:
	int _contentType = 0;
	int _itemType = 0;
	int _stateType = 0;
	Random* _random;
};