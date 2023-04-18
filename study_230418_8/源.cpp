#include <iostream>
#include <string>

using namespace std;

template<typename NameType, typename AgeType>
class Person
{
public:
	NameType name;
	AgeType age;
	Person(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
	void dispaly()
	{
		cout << this->name << "年龄是" << this->age << endl;
	}
};

void test1()
{
	Person < string, int >p1={ "张三", 18 };
	p1.dispaly();
	
	Person < string,int>p2={ "李四", 22 };

	cout << p2.name << "年龄是" << p2.age << endl;
}

void PrintPerson1(Person<string, int>& p1)
{
	p1.dispaly();
}

template<typename T1,typename T2>
void PrintPerson2(Person<T1,T2>& p)
{
	p.dispaly();
}

template<typename T>
void PrintPerson3(T&)
{
	T.dispaly();
}

void test2()
{
	Person<string, int> p1("张三",17);
	PrintPerson1(p1);
}
void test3()
{
	Person<string, int> p2("李四",18);
	PrintPerson2(p2);
}
void test4()
{
	Person<string, int> p3("王五",19);
	PrintPerson3(p3);
}

int main()
{
	test3();
	return 0;
}