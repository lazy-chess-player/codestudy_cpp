#include <iostream>
using namespace std;

class Date
{
public:
    void printDate()
    {
        cout << year << "-" << month << "-" << day << endl;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
private:
    int day, month, year;
};

int main()
{
    Date testDay;
    testDay.setDay(5);
    testDay.setMonth(10);
    testDay.setYear(2003);
    testDay.printDate();
    return 0;
}
