#include<iostream>
#include<string>

using namespace std;

class CodeLangue
{
public:
	double version;
	void GetClassName()
	{
		cout << "CodeLangue" << endl;
	}
	CodeLangue()
	{
		version = 1.1;
	}
};

class CPulsPuls:virtual public CodeLangue{};

class Java :virtual public CodeLangue{};

class IDE:public Java,public CPulsPuls
{
};

void test1()
{
	IDE i;
	cout << i.version << endl;
}

int main()
{
	test1();
	return 0;
}