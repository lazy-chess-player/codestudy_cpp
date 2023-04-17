#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class Entity
{
public:
	Entity() :c1('\0'), c2('\0'), c3('\0') {}
	Entity(char c_1, char c_2, char c_3) :c1(c_1), c2(c_2), c3(c_3) {}

	bool operator==(Entity& e)
	{
		if (this->c1 == e.c1 && this->c2 == e.c2 && this->c3 == e.c3)
			return true;
		return false;
	}


private:
	char c1;
	char c2;
	char c3;
};


void test()
{
	Entity e1('a','b','c');
	Entity e2('a','b','c');
	Entity e3('a','b','d');

	if (e1 == e2)
		cout << "e1和e2相等" << endl;
	if (e3 == e2)
		cout << "e2和e3相等" << endl;
	if (e1 == e3)
		cout << "e1和e3相等" << endl;
}

int main()
{
	test();
	return 0;
}