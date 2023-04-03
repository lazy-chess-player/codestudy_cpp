#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Stock 
{
public:
    Stock(const char* na, int q = 1000, double p = 8.98)
    {
        strcpy(Stockcode, na);
        quan = q;
        price = p;
    }
    void print()
    {
        cout << "Stockcode: " << Stockcode << endl;
        cout << "Quantity: " << quan << endl;
        cout << "Price: " << price << endl;
    }
private:
    char Stockcode[10];
    int quan;
    double price;
};

int main()
{
    Stock s1("600001", 3000, 5.75);
    Stock s2("600002");
    s1.print();
    cout << endl;
    s2.print();
    return 0;
}
