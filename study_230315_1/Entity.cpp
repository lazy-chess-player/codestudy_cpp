#include "Entity.h"
Entity::Entity()
{
	_id = "000000";
	_durable = 0;
	_name = "0";
}

Entity::Entity(std::string id,std::string name,int durable)
{
	_id = id;
	_durable = durable;
	_name = durable;
}

std::string Entity:: GetID()
{
	return _id;
}
std::string Entity:: GetName()
{
	return _name;
}
int Entity:: GetDurable()
{
	return _durable;
}

void Entity::ModifyID(std::string id)
{
	_id = id;
}
void Entity::ModifyName(std::string name)
{
	_name = name;
}
void Entity::ModifyDurable(int durable)
{
	_durable = durable;
}