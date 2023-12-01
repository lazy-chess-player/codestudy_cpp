#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int n; cin >> n;
    string s;cin >> s;
    int l = 0;
    int r = n - 1;
    int cnt1 = 0;
    int cnt2 = 0;
    while (l < r)
    {
        if (s[l] == s[r])
            cnt1 +=2;
        else
            cnt2 ++;
        l++;
        r--;
    }
    if (l == r)
        cnt1++;
    for (int i = 0; i < cnt2; i++)
    {
        cout<< '0';
    }
    if (n % 2)
    {
        for (int i = 0; i <= cnt1; i++)
        {
            cout<< '1';
        }
    }
    else
    {
        for (int i = 0; i <= cnt1; i++)
        {
            if (i % 2)
                cout<< '0';
            else
                cout<< '1';
        }
    }
    for (int i = 0; i < cnt2; i++)
    {
        cout<< '0';
    }
    cout<< endl;
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