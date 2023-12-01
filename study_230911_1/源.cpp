//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <unordered_map>
//
//#define fi first 
//#define se second 
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pii;
//
//
//void solve()
//{
//	int n; cin >> n;
//	vector<pii> nums(n);
//	vector<int> ans(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin>>nums[i].fi;
//		nums[i].se = i;
//	}
//	sort(nums.begin(), nums.end());
//	for (int i = n, j = 0; i > 0 && j < n; i--, j++)
//	{
//		ans[nums[j].se] = i;
//	}
//	for (auto x : ans)
//	{
//		cout << x << ' ';
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int t; cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


using namespace std;


void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> flag(n);
    int l = 0;
    int r = n - 1;
    int cnt1 = 0;
    int cnt2 = 0;
    while (l < r)
    {
        if (l == r)
        {
            cnt2++;
            break;
        }
        if (s[l] == s[r])
            cnt1++;
        else
            cnt2++;
    }
    int start = cnt1;
    int end = cnt1 + cnt2;
    for (int i = 0; i <= n; i++)
    {
        if (n % 2)
        {
            if (i >= start && i <= end)
            {
                cout << '1';
            }
            else
                cout << '0';
        }
        else
        {
            if (i >= start && i <= end)
            {
                cout << '0' + (start - i + 1) % 2;
            }
            else
                cout << '0';
        }
    }
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}