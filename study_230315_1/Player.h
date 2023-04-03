#pragma once
#include "Entity.h"
class Player :public Entity
{
public:
	int _hp;
	int _mp;
	int _speed;
	int _atk;
	int _def;
	Player();
	Player(std::string id, std::string name, int durable, int hp, int mp, int speed, int atk, int def);
private:
	std::string _carrer;
};