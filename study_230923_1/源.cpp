#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() 
{
    int n, p;
    cin >> n;
    vector<int> a(n);
    vector<double> q(n);
    double ans = n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        q[i] = p / 1e5;
    }
    for (int i = 0; i < n; i++)
    {
        double now = i;
        if (!q[i])
            continue;
        now = i + 1 + (1 / q[i] - 1) * (i - a[i] + 1);
        ans = min(ans, now);
    }
    printf("%.12f\n", ans);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


//3
//5
//0 1 2 0 1
//21735 25194 37976 89936 99999
//8
//0 0 2 2 4 3 4 1
//12839 27084 17777 35472 31951 64686 96898 0

