#ifndef __Entity_h__
#define __Entity_h__

#include <iostream>
#include <string>

class Printable
{
public:
    virtual void GetClassName() = 0;
};

class Entity : public Printable
{
private:
    std::string e_name;
public:
    void GetClassName() override
    {
        std::cout << "Entity" << std::endl;
    }
    Entity();
};
Entity::Entity()
{
    e_name = "Entity";
}
class Player : public Entity
{
public:
    void GetClassName() override
    {
        std::cout << "Player" << std::endl;
    }
    Player();
private:
    std::string p_name;
};
Player::Player()
{
    p_name = "Player";
}
#endif

int main()
{
	Entity e1;
	Entity* e = &e1;
	Player p1;
	Player* p =&p1;
	e->GetClassName();
	p->GetClassName();
	return 0;
}