#include<iostream>
#include<string>
//PrintClassName�����ӿ�
class Printtable
{
public:
	virtual std::string GetClassName() = 0;
};

class Entity:public Printtable
{
public:
	virtual std::string GetName()//�麯��������V��
	{
		return "Entity";
	}
	virtual std::string GetName() = 0;//���麯�����ӿڣ���ʵ�ַ�����������ʵ��

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

	std::string GetName() override//��Ǹ�д�������Ǳ�Ҫ
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
	Entity* e = new Entity();//�麯��δ����������ֱ��ʵ��
	//Entity* e = new Player(" ");//��������ʵ���ˣ����Ե���
	//std::cout << e->GetName() << std::endl;

	Player* p = new Player("Hello");
	//PrintName(p);

	Print(e);
	Print(p);

	std::cin.get();
	return 0;
}