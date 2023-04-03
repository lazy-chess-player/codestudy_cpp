#pragma once
#include <string>
class Entity
{
public:
	Entity();
	Entity(std::string id,std::string name,int durable);
	std::string GetID();
	std::string GetName();
	int GetDurable();
	void ModifyID(std::string id);
	void ModifyName(std::string name);
	void ModifyDurable(int durable);
private:
	std::string _id;
	std::string _name;
	int _durable;
};

