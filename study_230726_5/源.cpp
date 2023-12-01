#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<p> cnt;
        int mx = 0;
        int mn = 2147483646;
        int sz = 0;
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            cin >> a;
            if (cnt.empty() ||cnt[sz-1].first != a)
            {
                cnt.push_back({ a,1 });
                sz++;
            }
            else
            {
                cnt[sz-1].second++;
            }
        }
        sort(cnt.begin(), cnt.end());
        int l = 0;
        int r = l;
        int max_len = 0;
        for (int i = 0, j = i; i < sz; i++)
        {
            int len = 0;
            while (cnt[i].second < k && i < sz)
            {
                i++;
            }
            for (j = i; j < sz; j++)
            {
                if (cnt[j].second >= k && cnt[j].first == cnt[j - 1].first + 1)
                {
                    len++;
                }
                else
                    break;
            }
            if (len > max_len)
            {
                max_len = len;
                l = cnt[i].first;
                r = cnt[j - 1].first;
            }
        }
        if (max_len == 0)
            cout << -1 << endl;
        else
            cout << l << " " << r << endl;
    }
    return 0;
}
