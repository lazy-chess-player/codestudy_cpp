#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            if (temp == i + 1)
                cnt++;
        }
        int empty = n - cnt;
        if (cnt % 2)
            cout << cnt / 2 + 1 << endl;
        else
            cout << cnt / 2 << endl;

    }
    return 0;
}
