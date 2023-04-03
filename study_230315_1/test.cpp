#include "Player.h"
#include<iostream>
int main()
{
	Entity e1("000001","ÊµÌå",100);
	std::cout<< e1.GetID() << std::endl;
	Player p1("000003","Íæ¼Ò1",1000,100,60,3,45,34);
	std::cout << p1.GetID() << std::endl;
	std::cout << p1.GetName() << std::endl;
	std::cout << p1.GetDurable() << std::endl;
	std::cout << p1._hp << std::endl;
	std::cout << p1._mp << std::endl;
	std::cout << p1._atk << std::endl;
	std::cout << p1._def << std::endl;
	std::cout << p1._speed<< std::endl;
	return 0;
}