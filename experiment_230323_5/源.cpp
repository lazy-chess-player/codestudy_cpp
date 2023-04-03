//#include <iostream>
//using namespace std;
//class container
//{
//protected:
//    double  radius;
//public:
//    container(double  r) :radius(r){}
//    virtual  double surface_area() = 0;
//    virtual  double volume() = 0;
//};
//class cube : public container
//{
//public:
//    cube(double r) : container(r) {}
//    double surface_area()
//    {
//        return 6 * radius * radius;
//    }
//    double volume()
//    {
//        return radius * radius * radius;
//    }
//};
//
//class sphere : public container
//{
//public:
//    sphere(double r) : container(r) {}
//    double surface_area()
//    {
//        return 4 * 3.14 * radius * radius;
//    }
//    double volume()
//    {
//        return (4 / 3) * 3.14 * radius * radius * radius;
//    }
//};
//
//class cylinder :public container
//{
//public:
//    int high;
//    cylinder(double r, double h) :container(r), high(h) {};
//    double surface_area()
//    {
//        return 3.14 * radius * high + radius * radius * 3.14 * 2;
//    }
//    double volume()
//    {
//        return 3.14 * radius * radius * high;
//    }
//};
//
//int main()
//{
//    cube c(6);
//    sphere s(5);
//    cylinder cy(5, 6);
//
//    cout << "������ı����Ϊ��" << c.surface_area() << "���Ϊ��" << c.volume() << endl;
//    cout << "��ı����Ϊ��" << s.surface_area() << "���Ϊ��" << s.volume() << endl;
//    cout << "Բ����ı����Ϊ��" << cy.surface_area() << "���Ϊ��" << cy.volume() << endl;
//
//    return 0;;
//}

#include<iostream>
int my_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans *= a;
        }
        b /= 2;
        a *= a;
    }
    return ans;
}
int main()
{
    std::cout << my_pow(3, 7) << std::endl;
    return 0;
}