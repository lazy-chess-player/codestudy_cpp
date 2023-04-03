#include "Player.h"

Player::Player()
{
	ModifyDurable(1);
	ModifyID("000002");
	ModifyName("0");
	_mp = 1;
	_hp = 1;
	_speed = 0;
	_atk = 0;
	_def = 0;
}

Player::Player(std::string id, std::string name, int durable, int hp, int mp, int speed, int atk, int def)
{
	ModifyDurable(durable);
	ModifyID(id);
	ModifyName(name);
	_mp = mp;
	_hp = hp;
	_speed = speed;
	_atk = atk;
	_def = def;
}