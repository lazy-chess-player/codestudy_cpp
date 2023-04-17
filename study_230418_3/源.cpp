#include <iostream>
#include <string>

using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger m_int);
	friend MyInteger& operator--(MyInteger& m_int);
	friend MyInteger operator--(MyInteger& m_int, int);
public:
	MyInteger() :val(0) {}

	MyInteger& operator++()//��Ա����ʵ��ǰ��++
	{
		this->val++;
		return *this;//�����÷��ر����γ���ʽ����
	}
	MyInteger operator++(int)//��Ա����ʵ�ֺ���++,����ռλ��������ǰ��++��������
	{
		MyInteger temp = *this;//����һ��������ű�����ֵ���ڷ���
		this->val++;
		return temp;//���ܷ������ã���Ϊ���ص���һ����ջ���ϵ���ʱ�࣬�ᱻ�ͷ�
	}
private:
	int val;
};

MyInteger& operator--(MyInteger& m_int)//ȫ�ֺ���ʵ��ǰ��--,�����ͷ���ֵ���������û���ָ�������ȷ���޸��������ֵ
{
	m_int.val--;
	return m_int;
}
MyInteger operator--(MyInteger& m_int,int)//ȫ�ֺ���ʵ�ֺ���--
{
	MyInteger temp = m_int;
	m_int.val--;
	return temp;//����ֵ����������
}

ostream& operator<<(ostream& cout, const MyInteger m_int)
{
	cout << m_int.val;
	return cout;
}

void tetst1()//ǰ�����������
{
	MyInteger MyInt;

	cout << ++(++MyInt) << endl;
	cout << MyInt << endl;

	cout << --(--MyInt) << endl;
	cout << MyInt << endl;
}

void tetst2()
{
	MyInteger MyInt;

	cout << (MyInt++)++ << endl;
	cout << MyInt++ << endl;

	cout << MyInt-- << endl;
	cout << MyInt-- << endl;
	cout << MyInt << endl;
}



int main()
{
	tetst2();
	return 0;
}