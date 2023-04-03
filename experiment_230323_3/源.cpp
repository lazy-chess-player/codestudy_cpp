#include<iostream>
using namespace std;
class A
{
public:
    A(int a)
    {
        x = a;
        cout << "调用类A构造函数" << endl;
    }
    ~A() {};
    int getX() { return x; }
protected:
    int x;
};
class B :virtual public A
{
public:
    B(int b) :A(b)  //将此处补充完整
    {
        cout << "调用类B构造函数" << endl;
    }
    ~B() {};
};
class C : public virtual A
{
public:
    C(int  c) :A(c)   //将此处补充完整
    {
        cout << "调用类C构造函数" << endl;
    }
    ~C() {};
};
class D :public B, public C
{
public:
    D(int d) :A(d), B(d), C(d) //此处将D类的构造函数的定义补充完成
    {
        cout << "调用类D构造函数" << endl;
    }
    ~D() {};
};
int main()
{
    D d(3);
    cout << "X=" << d.getX() << endl;
}