#include<iostream>
using namespace std;

class base1
{
public:
    base1(int a):x1(a){}
    void print(){cout<<"x1="<<x1<<endl;}
protected:
    int x1;
};
class base2:public base1
{
public:
    base2(int a,int b):base1(a),x2(b){}
    void print(){cout<<"x2="<<x2<<endl;}
protected:
    int x2;
};
class base3:public base1
{
public:
    base3(int a,int c):base1(a),x3(c){}
    void print(){cout<<"x3="<<x3<<endl;}
protected:
    int x3;
};
class derived:public base2,public base3
{
public:
    derived(int a,int b,int c,int d):base2(a,b),base3(a,c),xd(d){}
    void print(){cout<<"xd="<<xd<<endl;}
private:
    int xd;
};
int main()
{
    derived d(10,20,30,40);
    d.base1::print();
    d.base2::print();
    d.base3::print();
    d.print();
    return 0;
}