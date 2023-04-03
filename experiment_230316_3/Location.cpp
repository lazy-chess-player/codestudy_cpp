#include <iostream>
#include <cmath>
using namespace std;

class Location
{
public:
    Location(double a, double b) : x(a), y(b) {}
    double Getx() { return x; }
    double Gety() { return y; }
    double distance(Location& p)
    {
        return sqrt((x - p.Getx()) * (x - p.Getx()) + (y - p.Gety()) * (y - p.Gety()));
    }
    friend double distance(Location& p1, Location& p2);
private:
    double x, y;
};

double distance(Location& p1, Location& p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
    Location A(-3, -4); //第一象限
    Location B(-2, 1);  //第二象限
    cout << "A(" << A.Getx() << "," << A.Gety() << "),B(" << B.Getx() << "," << B.Gety() << ")" << endl;
    cout << "Distance1=" << A.distance(B) << endl; 
    cout << "Distance2=" << distance(A, B) << endl; 
    return 0;
}
