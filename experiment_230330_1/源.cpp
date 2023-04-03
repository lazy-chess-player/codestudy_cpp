#include<iostream>
using namespace std;
class B
{
public:
    virtual void f1(double x)
    {
        cout << "B::f1(double)" << x << endl;
    }
    virtual void  f2(double x)
    {
        cout << "B::f2(double)" << 2 * x << endl;
    }
    void f3(double x)
    {
        cout << "B::f3(double)" << 3 * x << endl;
    }
};
class D :public B
{
public:
    virtual void f1(double x)
    {
        cout << "D::f1(double)" << x << endl;
    }
    virtual void  f2(int x)
    {
        cout << "D::f2(int)" << 2 * x << endl;
    }
    void f3(double x)
    {
        cout << "D::f3(double)" << 3 * x << endl;
    }
};
void main()
{
    B* pb, b;
    D  d;
    pb = &b;
    pb->f1(1.23);
    pb->f2(1.23);
    pb->f2(2);
    pb->f3(1.23);
    pb = &d;
    pb->f1(1.23);
    pb->f2(1.23);
    pb->f2(2);
    pb->f3(1.23);
}
