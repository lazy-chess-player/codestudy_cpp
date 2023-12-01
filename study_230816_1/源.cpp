#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int t;
    scanf("%d",&t);

    while (t--)
    {
        int d1, d2, temp;
        int y, m;
        char day[] = { '\0' };
        scanf("%d%d%d", &y, &m, &d1);
        scanf("%s", &day);
        scanf("%d%d%d", &y, &m, &d1);

        if (day == "Monday") temp = 0;
        if (day == "Tuesday") temp = 1;
        if (day == "Wednesday") temp = 2;
        if (day == "Thursday") temp = 3;
        if (day == "Friday") temp = 4;

        if (d1 <= d2)
            temp = (temp + (d2 - d1) % 5) % 5;
        else 
            temp = (temp + 5 - (d1 - d2) % 5) % 5;

        if (temp == 0) printf("Monday\n");
        if (temp == 1) printf("Tuesday\n");
        if (temp == 2) printf("Wednesday\n");
        if (temp == 3) printf("Thursday\n");
        if (temp == 4) printf("Friday\n");
    }

    return 0;
}