#include <iostream>
#include <string>

using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger m_int);
	friend MyInteger& operator--(MyInteger& m_int);
	friend MyInteger operator--(MyInteger& m_int, int);
public:
	MyInteger() :val(0) {}

	MyInteger& operator++()//成员函数实现前置++
	{
		this->val++;
		return *this;//解引用返回本身，形成链式函数
	}
	MyInteger operator++(int)//成员函数实现后置++,利用占位参数来与前置++进行区分
	{
		MyInteger temp = *this;//创建一个容器存放本来的值用于返回
		this->val++;
		return temp;//不能返回引用，因为返回的是一个在栈区上的临时类，会被释放
	}
private:
	int val;
};

MyInteger& operator--(MyInteger& m_int)//全局函数实现前置--,参数和返回值必须是引用或者指针才能正确地修改类里面的值
{
	m_int.val--;
	return m_int;
}
MyInteger operator--(MyInteger& m_int,int)//全局函数实现后置--
{
	MyInteger temp = m_int;
	m_int.val--;
	return temp;//返回值不能是引用
}

ostream& operator<<(ostream& cout, const MyInteger m_int)
{
	cout << m_int.val;
	return cout;
}

void tetst1()//前置运算符重载
{
	MyInteger MyInt;

	cout << ++(++MyInt) << endl;
	cout << MyInt << endl;

	cout << --(--MyInt) << endl;
	cout << MyInt << endl;
}

void tetst2()
{
	MyInteger MyInt;

	cout << (MyInt++)++ << endl;
	cout << MyInt++ << endl;

	cout << MyInt-- << endl;
	cout << MyInt-- << endl;
	cout << MyInt << endl;
}



int main()
{
	tetst2();
	return 0;
}