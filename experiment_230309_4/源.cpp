#include<iostream>
using namespace std;
class coordinate
{
public:
    coordinate(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    coordinate(coordinate&);
    ~coordinate()
    {
        cout << "Destructor is called\n";
    }
    int getx() { return  x; }
    int gety() { return  y; }
private:  int x, y;
};
coordinate::coordinate(coordinate& p)
{
    x = p.x;
    y = p.y;
    cout << "copy_constructor is called\n";
}
void main()
{
    coordinate  p1(3, 4);
    coordinate  p2(p1);
    coordinate  p3 = p2;
    cout << "p3=(" << p3.getx() << ',' << p3.gety() << ")\n";
}