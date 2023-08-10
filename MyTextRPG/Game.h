#pragma once

class Player;
class Field;
class Random;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

private:
	Player* _player;
	Field* _field;
	Random* _random;
};