#include <iostream>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal ���캯�����ã�" << endl;
	}
	virtual void Speak() = 0;
	//������������virtual�ؼ��֣��������������
	//virtual ~Animal()
	//{
	//	cout << "Animal�������������ã�" << endl;
	//}
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "Animal ����������������!"<<endl;
}

class Cat :public Animal {
public:
	Cat(string name)
	{
		cout << "cat���캯�����ã�" << endl;
		m_Name = new string(name);
	}
	virtual void Speak()
	{
		cout << *m_Name << "Сè��˵����" << endl;
	}
	~Cat()
	{
		cout << "cat�����������ã�" << endl;
		if (this->m_Name = NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
public:
	string* m_Name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->Speak();

	// ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ������������
	//���������������������ͨ������ָ���ͷ��������
	delete animal;
}

int main()
{
	test01();

	system("pause");
	return 0;
}