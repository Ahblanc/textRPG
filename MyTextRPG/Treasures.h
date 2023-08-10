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
	IC_None, // 꽝
	IC_Sword, // 공격 증가
	IC_Armor, // 수비 증가
	IC_Shoes, // 스피드 증가
	IC_Potion, // 체력 증가
	IC_CurseSword, // 공격 감소
	IC_CurseArmor, // 수비 감소
	IC_CurseShoes, // 스피드 감소
	IC_CursePotion, // 체력 감소
};

enum StateContent
{
	SC_None, // 꽝
	SC_Blessing, // 축복
	SC_Curse // 저주
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