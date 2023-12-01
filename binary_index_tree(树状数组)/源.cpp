#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

ll bt[N]{ 0 };
ll a[N]{ 0 };
int n = 0;
int m = 0;
int temp;

int lowbit(int x)
{
	return x & -x;
}

void add(int p, int k)
{
	while (p <= n)
	{
		bt[p] += k;
		p += lowbit(p);
	}
}

ll ask(int p)
{
	ll res = 0;
	while (p > 0)
	{
		res += bt[p];
		p -= lowbit(p);
	}
	return res;
}


void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int opt, x, y, k;
	while (m--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y >> k;
			add(x, k);
			add(y + 1, -k);
		}
		else if (opt == 2)
		{
			cin >> x;
			cout << a[x] + ask(x) << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}