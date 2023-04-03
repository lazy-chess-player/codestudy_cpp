#include<iostream>
#include<string>
//PrintClassName函数接口
class Printtable
{
public:
	virtual std::string GetClassName() = 0;
};

class Entity:public Printtable
{
public:
	virtual std::string GetName()//虚函数，创建V表
	{
		return "Entity";
	}
	virtual std::string GetName() = 0;//纯虚函数，接口，不实现方法，由子类实现

	std::string GetClassName() override
	{
		return "Entity";
	}
};

void PrintName(Entity* entity)
{
	 std::cout << entity->GetName() << std::endl;
}

void Print(Printtable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		:m_Name(name){}

	std::string GetName() override//标记覆写函数，非必要
	{
		return m_Name;
	}

	std::string GetClassName() override
	{
		return "Player";
	}
};

int main()
{
	Entity* e = new Entity();//虚函数未创建，不能直接实现
	//Entity* e = new Player(" ");//在子类中实现了，可以调用
	//std::cout << e->GetName() << std::endl;

	Player* p = new Player("Hello");
	//PrintName(p);

	Print(e);
	Print(p);

	std::cin.get();
	return 0;
}