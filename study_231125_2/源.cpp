#include <iostream>
#include <bitset>

using namespace std;

typedef long long ll;

const int N = 1e8 + 5;

bitset<N> pri;

int primes[N];
int p = 0;

void EulerSieve(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!pri[i])
			primes[++p] = i;
		for (int j = 1; primes[j] * i <= n; ++j)
		{
			pri[primes[j] * i] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
}

int n, k;
int cnt = 0;

int a[25];

void dfs(int i, int num, int sum)
{
	if (num == 0) 
	{
		if (!pri[sum])
			cnt++;
		return;
	}
	if (n - i + 1 < num) 
		return;
	for (int j = i; j <= n; j++) 
	{
		dfs(j + 1, num - 1, sum + a[j]);
	}
	return;
}

void solve()
{
    cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(1, k, 0);
	cout << cnt << endl;
}

int main()
{
	EulerSieve(N - 5);
	solve();
	return 0;
}