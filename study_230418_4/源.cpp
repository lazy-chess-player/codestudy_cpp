#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class Entity
{
	friend ostream& operator<<(ostream& cout, const Entity& e);
public:
	Entity():p_val(NULL){}
	Entity(int num)
	{
		p_val = new int(num);
	}
	~Entity()
	{
		if (p_val)
		{
			delete p_val;
			p_val = NULL;
		}
	}

	Entity& operator=(Entity& e)//���ﴫ��ʹ����������Ϊֵ����ʱ�����ϵͳ��Ĭ�Ͽ������캯����ǳ������������ʱ������������ǰ�ͷ���e�Ķ����ڴ�
	{
		if (p_val)
		{
			delete p_val;
			p_val = NULL;
		}//�Ƚ������ڴ��ͷţ���ֹ������ڽ��и�ֵ

		p_val = new int(*e.p_val);

		return *this;//���������γ���ʽ����
	}
private:
	int* p_val;
};

ostream& operator<<(ostream& cout, const Entity& e)
{
	cout << *e.p_val;
	return cout;
}

void test()
{
	Entity e1(10);
	Entity e2(20);
	Entity e3(30);

	//e1 = e2;���������ṩĬ�����ظ�ֵ����������ֻ��ǳ����

	e1 = e2 = e3;

	cout << "e1��ֵΪ��" << e1 << endl;

	cout << "e2��ֵΪ��" << e2 << endl;
	
	cout << "e3��ֵΪ��" << e3 << endl;
}

int main()
{
	test();
	return 0;
}