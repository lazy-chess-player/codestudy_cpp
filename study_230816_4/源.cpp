#include <iostream>
#include <string>
#include <cmath>

#define max(x,y) (x)>(y)?(x):(y)

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--) 
    {
        ll n, k;
        cin >> n >> k;

        string op;
        cin >> op;

        ll x = 0;
        ll y = 0;
        ll max_dis = 0;
        for (int i = 0; i < n; i++)
        {
            if (op[i] == 'U')
                y++;
            else if (op[i] == 'R')
                x++;
            else if (op[i] == 'L')
                x--;
            else if (op[i] == 'D')
                y--;
            max_dis = max(max_dis, (abs(x) + abs(y)));
        }
        x *= (k - 1);
        y *= (k - 1);
        for (int i = 0; i < n; i++)
        {
            if (op[i] == 'U')
                y++;
            else if (op[i] == 'R')
                x++;
            else if (op[i] == 'L')
                x--;
            else if (op[i] == 'D')
                y--;
            max_dis = max(max_dis, abs(x) + abs(y));
        }
        cout << max_dis << endl;
    }
    return 0;
}
