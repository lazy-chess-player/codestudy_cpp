#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class Entity
{
public:
	int _val;

	Entity()
	{
		_val = 0;
	};
	Entity(int id,int num):_val(num){}

	Entity operator+(const Entity& e)//��ĳ�Ա����ʵ�����������
	{
		Entity temp;
		temp._val = this->_val + e._val;
		return temp;
	}
};

Entity operator*(const Entity& e1,const Entity& e2)//ȫ�ֺ���ʵ�����������
{
	Entity temp;
	temp._val = e1._val * e2._val;
	return temp;
}


void test1()//˫Ŀ�������+��-��*��/��%��������
{
	Entity e1 = {0,5};
	Entity e2 = Entity(0,7);
	Entity e3(0, 9);

	Entity e4 = e1 + e2;
	cout <<"ֵ��" << e4._val << endl;

	Entity e5 = e1 * e3;
	cout << "ֵ��" << e5._val << endl;
}

int main()
{
	test1();
	return 0;
}

