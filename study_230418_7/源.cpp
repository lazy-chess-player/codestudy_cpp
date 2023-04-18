#include <iostream>

using namespace std;

class Entity
{
public:
	Entity(int num) :val(num) {}
	int val;
};

ostream& operator<<(ostream& cout,Entity& e1)
{
	cout << e1.val;
	return cout;
}

template<typename T>
void MySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<> void MySwap(Entity& e1, Entity& e2)
{
	int temp = e1.val;
	e1.val = e2.val;
	e2.val = temp;
}

void test1()
{
	double a = 1.37;
	double b = 4.25;
	MySwap(a, b);
	cout << a << " " << b << endl;

	MySwap<double>(a, b);
	cout << a << " " << b << endl;
}

void test2()
{
	Entity e1(10);
	Entity e2(20);
	MySwap(e1, e2);
	cout << e1 << " " << e2 << endl;

}

int main()
{
	test2();
	return 0;
}