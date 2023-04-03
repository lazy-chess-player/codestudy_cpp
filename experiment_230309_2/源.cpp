#include"counter.h"
int main()
{
	int num = 0;
	std::cin >> num;
	counter Counter1(num);
	Counter1.print();
	Counter1.decrement();
	std::cout << Counter1.getvalue() << std::endl;
	Counter1.increment();
	Counter1.print();
	return 0;
}