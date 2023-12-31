#include <iostream>
using namespace std;

class Base
{
public:
    void setx(int i) { x = i; }
    int  getx() { return x; }
private:
    int x;
};
class Derived :public Base
{
public:
    void sety(int i) { y = i; }
    int  gety() { return y; }
    void  show() { cout << "Base::x = " << x << endl; }
    int y;
};
void main()
{
    Derived  bb;
    bb.setx(16);
    bb.sety(25);
    bb.show();
    cout << "Base::x = " << bb.x << endl;
    cout << "Derived::y =" << bb.y << endl;
    cout << "Base::x = " << bb.getx() << endl;
    cout << "Derived::y = " << bb.gety() << endl;
}
