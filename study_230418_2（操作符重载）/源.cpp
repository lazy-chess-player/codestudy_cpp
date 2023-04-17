#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class Entity
{
	friend ostream& operator<<(ostream& cout, const Entity& e);//可以利用友元函数使得运算符重载函数直接访问私有成员

public:
	Entity()
	{
		_num1 = 0;
		_num2 = 0;
	};
	Entity(int num1, int num2) :_num1(num1), _num2(num2) {}

private:
	int _num1;
	int _num2;

};

ostream& operator<<(ostream& cout, const Entity& e)//只能利用全局函数重载
{
	cout << "Num1:" << e._num1<< " Num2:" << e._num2;
	return cout;//返回输出流ostream的引用，形成链式访问
}

void test1()//左移运算符<<的重载
{
	Entity e1(123, 567);
	cout << e1 << "两个数字已经输出" << endl;
}

int main()
{
	test1();
	return 0;
}