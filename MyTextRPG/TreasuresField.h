#pragma once
#include "Field.h"

class Treasures;
class Player;

class TreasuresField : public Field
{
public:
	TreasuresField();
	virtual ~TreasuresField();

	void Init();
	int SelectChoice();

	void TreasuresOpen(int, Player*);

private:
	Treasures* _treasures1;
	Treasures* _treasures2;
	Treasures* _treasures3;
};

