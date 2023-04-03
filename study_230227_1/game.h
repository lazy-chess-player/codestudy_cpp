#pragma once
#include<iostream>
class Entity
{
public:
	double x, y;
	const char* Name;
	int ID;
	Entity()
	{
		x = 0.0f;
		y = 0.0f;
		Name = "Empty";
		ID = 0;
	}
	Entity(int id, const char* name, double X, double Y)
	{
		x = X;
		y = Y;
		Name = name;
		ID = id;
	}
	enum Status
	{
		Death = -1, Dying, Alive
	};
	~Entity()
	{
		std::cout << "创建实体" << std::endl;

	}
};
class Player :public Entity
{
public:
	double Speed;
	Player()
	{
		Speed = 1.0f;
	};
	void SetMyStatus(Status status)
	{
		static int SubstanceNumber = 0;
		MyStatus = status;
		SubstanceNumber++;
	};
	void move(double& x, double& y, double speed, double time);
private:
	Status MyStatus;
};
