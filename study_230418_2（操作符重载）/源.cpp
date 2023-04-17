#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class Entity
{
	friend ostream& operator<<(ostream& cout, const Entity& e);//����������Ԫ����ʹ����������غ���ֱ�ӷ���˽�г�Ա

public:
	Entity()
	{
		_num1 = 0;
		_num2 = 0;
	};
	Entity(int num1, int num2) :_num1(num1), _num2(num2) {}

private:
	int _num1;
	int _num2;

};

ostream& operator<<(ostream& cout, const Entity& e)//ֻ������ȫ�ֺ�������
{
	cout << "Num1:" << e._num1<< " Num2:" << e._num2;
	return cout;//���������ostream�����ã��γ���ʽ����
}

void test1()//���������<<������
{
	Entity e1(123, 567);
	cout << e1 << "���������Ѿ����" << endl;
}

int main()
{
	test1();
	return 0;
}