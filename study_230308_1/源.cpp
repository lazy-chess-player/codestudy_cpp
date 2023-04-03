#include"Entity.h"

int main()
{
	std::string name1 = " Cherno";
	name1 += " hello ";//+=±ªstring÷ÿ‘ÿ¡À

	std::string name2 = std::string(" Cherno")+" hello! ";

	std::cout << name1 << name1.size() << std::endl;
	std::cout << name2 << name2.size() << std::endl;

	std::cout << name2 << name2.find("no") << std::endl;

	std::cin.get();
	return 0;
}