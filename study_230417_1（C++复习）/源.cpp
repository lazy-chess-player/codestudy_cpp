#include<iostream>
#include<string>

using namespace std;

//成员类
class Phone
{
public:
	Phone();
	~Phone();
};
Phone::Phone()
{
	cout << "Phone构造函数调用" << endl;
}
Phone::~Phone()
{
	cout << "Phone析构函数调用" << endl;
}

//基类
class Person
{
	//友元函数的声明
	friend void SetWeigght(Person& p,int weight);//友元函数声明
	friend class Wallet;//友元类声明
	friend void Eatfood::AddWeight(Person* ptr);//类成员做友元函数

public://public权限，谁都可以访问

	Person()//默认构造函数
	{
		cout << "Person默认构造函数调用" << endl;
	}

	Person(int age, int height,int weight):_money(0)//含参构造函数
	{
		cout << "Person含参构造函数调用" << endl;
		this->age = age;//this指针指向对象本身
		_weight = weight;
		*_height = height;
	}

	Person(const Person& p):_money(0)//浅拷贝构造函数（默认构造函数）
	{
		cout << "Person浅拷贝构造函数调用" << endl;
		this->age = p.age;//值传递，将被拷贝对象的成员变量age的值赋值给新的对象的age
		_weight = p._weight;//同上
		_money = p._money;//同上

		_height = p._height;//进行值传递，新的对象和被拷贝的对象的_height的指针指向的是同一块堆区空间
	}

	Person(const Person& p,char mode) :_money(0)//深拷贝构造函数
	{
		if (mode != 'h')
			return;
		cout << "Person深拷贝构造函数调用" << endl;
		this->age = p.age;//成员变量直接进行值传递
		_weight = p._weight;//同上
		_money = p._money;//同上

		_height = new int(*_height);//从堆区重新开一块空间给新的对象
	}
	
	~Person()//析构函数
	{
		cout << "Person析构函数调用" << endl;
		if (_height)
			delete _height;//释放堆区空间
		_height = NULL;
	}

	int age;
	int* _height = new int;//new开辟空间存放高度
	
	//Phone a;//类做成员，构造时先构造成员类Phone，再构造Person类，释放时，先释放Person类，再释放Phone类，栈的结构

private://private权限，只有类内和友元函数可以访问
	int _weight;

	void GetClassName()
	{
		cout << "Person" << endl;
	};

protected://protect权限，子类和友元函数可以访问
	int _money;
};

//友元类
class Wallet
{
public:
	void AddMoney(Person* ptr)
	{
		cout << "捡到100元" << endl;
		ptr->_money += 100;
	}
};

//成员函数做友元函数
class Eatfood
{
public:
	void AddWeight(Person* ptr);
};
void Eatfood::AddWeight(Person* ptr)
{
	
}

void SetWeigght(Person& p, int weight)
{
	cout << "将Person的重量设置为" << weight << endl;
	p._weight = weight;
}

void test1() //成员类的构造和析构顺序测试
{
	Person p1;
}

void test2()//不同的构造函数以及构造函数的不同调用方式
{
	Person p1;
	Person p2(18, 170, 120);
	//Person p3(p2);释放了已经释放的堆区空间，直接报错
	Person p3(p2, 'h');

	Person p4 = Person(16, 164, 110);//显式调用
	Person p5 = { 17,175,135 };//隐式调用
}

void test03()
{

}

int main()
{
	//test1();
	
	test2();
	
	return 0;
}