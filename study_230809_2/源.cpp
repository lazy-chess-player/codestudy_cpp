#include <iostream>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int d = abs(x - z);
        if (x < z)
        {
            if (d > y)
            {
                cout << -1 << endl;
                break;
            }
            else if (d == y)
            {
                cout << y << endl;
            }
            else
            {
                cout << y - d << endl;
                break;
            }
        }
    }
    return 0;
}
