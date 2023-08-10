#pragma once
#include <random>
using namespace std;

class Random
{
public:
	Random() : _mt(_rd()) {};

	int GetRandomValue(int num1, int num2)
	{
		uniform_int_distribution<int> distrib(num1, num2);
		return distrib(_mt);
	};

private:
	random_device _rd;
	mt19937 _mt;
};

