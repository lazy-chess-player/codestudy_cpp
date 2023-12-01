#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
typedef long long ll;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<p> arr;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.emplace_back(i + 1, num);
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<ll> pre;
        ll sum = 0;
        int start = 0;
        for (int i = 0; i < n; i++) 
        {
            sum += arr[i].second;
            pre.push_back(sum);
        }
        for (int i = 0; i < pre.size() - 1; i++) 
        {
            if (pre[i] < arr[i + 1].second)
                start = i + 1;
        }
        vector<int> ans;
        for (int j = start; j < n; j++)
        {
            ans.push_back(arr[j].first);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() <<endl;
        for (int num : ans) 
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
