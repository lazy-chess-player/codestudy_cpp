#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<p> intervals(n);
        vector<int> bit(n);
        for (int i = 0; i < n; i++)
        {
            cin>>intervals[i].first>>intervals[i].second;
        }
        int ans = 0;
        for (int i = 29; i >= 0; i--) 
        {
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (!flag)
                    break;
                int left = bit[j] | (1 << i);
                int right = bit[j] | ((2 << i) - 1);
                if (left > intervals[j].second || right < intervals[j].first)
                    flag = false;
            }
            if (flag)
            {
                for (int j = 0; j < n; j++)
                    bit[j] |= 1 << i;
                ans |= 1 << i;
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    int left = bit[j] | (1 << i);
                    int right = bit[j] | ((2 << i) - 1);
                    if (left <= intervals[j].second && right >= intervals[j].first )
                        bit[j] |= 1 << i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}



