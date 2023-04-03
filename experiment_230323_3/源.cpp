#include<iostream>
using namespace std;
class A
{
public:
    A(int a)
    {
        x = a;
        cout << "������A���캯��" << endl;
    }
    ~A() {};
    int getX() { return x; }
protected:
    int x;
};
class B :virtual public A
{
public:
    B(int b) :A(b)  //���˴���������
    {
        cout << "������B���캯��" << endl;
    }
    ~B() {};
};
class C : public virtual A
{
public:
    C(int  c) :A(c)   //���˴���������
    {
        cout << "������C���캯��" << endl;
    }
    ~C() {};
};
class D :public B, public C
{
public:
    D(int d) :A(d), B(d), C(d) //�˴���D��Ĺ��캯���Ķ��岹�����
    {
        cout << "������D���캯��" << endl;
    }
    ~D() {};
};
int main()
{
    D d(3);
    cout << "X=" << d.getX() << endl;
}