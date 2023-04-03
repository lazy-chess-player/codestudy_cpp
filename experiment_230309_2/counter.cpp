#include "counter.h"
counter:: counter(int number)
{
	value = number;
}
void counter::increment()
{
	value++;
}
void counter::decrement()
{
	value--;
}
int counter::getvalue()
{
	return value;
}
void counter::print()
{
	std::cout << value << std::endl;
}