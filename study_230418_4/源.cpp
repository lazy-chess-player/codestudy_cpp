#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class Entity
{
	friend ostream& operator<<(ostream& cout, const Entity& e);
public:
	Entity():p_val(NULL){}
	Entity(int num)
	{
		p_val = new int(num);
	}
	~Entity()
	{
		if (p_val)
		{
			delete p_val;
			p_val = NULL;
		}
	}

	Entity& operator=(Entity& e)//这里传参使用引用是因为值传参时会调用系统的默认拷贝构造函数（浅拷贝）创建临时变量，导致提前释放了e的堆区内存
	{
		if (p_val)
		{
			delete p_val;
			p_val = NULL;
		}//先将堆区内存释放，防止溢出，在进行赋值

		p_val = new int(*e.p_val);

		return *this;//返回自身形成链式函数
	}
private:
	int* p_val;
};

ostream& operator<<(ostream& cout, const Entity& e)
{
	cout << *e.p_val;
	return cout;
}

void test()
{
	Entity e1(10);
	Entity e2(20);
	Entity e3(30);

	//e1 = e2;编译器会提供默认重载赋值操作符，但只是浅拷贝

	e1 = e2 = e3;

	cout << "e1的值为：" << e1 << endl;

	cout << "e2的值为：" << e2 << endl;
	
	cout << "e3的值为：" << e3 << endl;
}

int main()
{
	test();
	return 0;
}