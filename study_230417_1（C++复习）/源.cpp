#include<iostream>
#include<string>

using namespace std;

//��Ա��
class Phone
{
public:
	Phone();
	~Phone();
};
Phone::Phone()
{
	cout << "Phone���캯������" << endl;
}
Phone::~Phone()
{
	cout << "Phone������������" << endl;
}

//����
class Person
{
	//��Ԫ����������
	friend void SetWeigght(Person& p,int weight);//��Ԫ��������
	friend class Wallet;//��Ԫ������
	friend void Eatfood::AddWeight(Person* ptr);//���Ա����Ԫ����

public://publicȨ�ޣ�˭�����Է���

	Person()//Ĭ�Ϲ��캯��
	{
		cout << "PersonĬ�Ϲ��캯������" << endl;
	}

	Person(int age, int height,int weight):_money(0)//���ι��캯��
	{
		cout << "Person���ι��캯������" << endl;
		this->age = age;//thisָ��ָ�������
		_weight = weight;
		*_height = height;
	}

	Person(const Person& p):_money(0)//ǳ�������캯����Ĭ�Ϲ��캯����
	{
		cout << "Personǳ�������캯������" << endl;
		this->age = p.age;//ֵ���ݣ�������������ĳ�Ա����age��ֵ��ֵ���µĶ����age
		_weight = p._weight;//ͬ��
		_money = p._money;//ͬ��

		_height = p._height;//����ֵ���ݣ��µĶ���ͱ������Ķ����_height��ָ��ָ�����ͬһ������ռ�
	}

	Person(const Person& p,char mode) :_money(0)//������캯��
	{
		if (mode != 'h')
			return;
		cout << "Person������캯������" << endl;
		this->age = p.age;//��Ա����ֱ�ӽ���ֵ����
		_weight = p._weight;//ͬ��
		_money = p._money;//ͬ��

		_height = new int(*_height);//�Ӷ������¿�һ��ռ���µĶ���
	}
	
	~Person()//��������
	{
		cout << "Person������������" << endl;
		if (_height)
			delete _height;//�ͷŶ����ռ�
		_height = NULL;
	}

	int age;
	int* _height = new int;//new���ٿռ��Ÿ߶�
	
	//Phone a;//������Ա������ʱ�ȹ����Ա��Phone���ٹ���Person�࣬�ͷ�ʱ�����ͷ�Person�࣬���ͷ�Phone�࣬ջ�Ľṹ

private://privateȨ�ޣ�ֻ�����ں���Ԫ�������Է���
	int _weight;

	void GetClassName()
	{
		cout << "Person" << endl;
	};

protected://protectȨ�ޣ��������Ԫ�������Է���
	int _money;
};

//��Ԫ��
class Wallet
{
public:
	void AddMoney(Person* ptr)
	{
		cout << "��100Ԫ" << endl;
		ptr->_money += 100;
	}
};

//��Ա��������Ԫ����
class Eatfood
{
public:
	void AddWeight(Person* ptr);
};
void Eatfood::AddWeight(Person* ptr)
{
	
}

void SetWeigght(Person& p, int weight)
{
	cout << "��Person����������Ϊ" << weight << endl;
	p._weight = weight;
}

void test1() //��Ա��Ĺ��������˳�����
{
	Person p1;
}

void test2()//��ͬ�Ĺ��캯���Լ����캯���Ĳ�ͬ���÷�ʽ
{
	Person p1;
	Person p2(18, 170, 120);
	//Person p3(p2);�ͷ����Ѿ��ͷŵĶ����ռ䣬ֱ�ӱ���
	Person p3(p2, 'h');

	Person p4 = Person(16, 164, 110);//��ʽ����
	Person p5 = { 17,175,135 };//��ʽ����
}

void test03()
{

}

int main()
{
	//test1();
	
	test2();
	
	return 0;
}