#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define fi first
#define se second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef vector<pss> vpss;
typedef queue <int> qi;
typedef queue <ll> qll;
typedef queue <pii> qpii;

const int N = 1e5 + 5;

int dp[105][1005];

void solve()
{
	int t, m;
	cin >> t >> m;
	vi time(m + 1);
	vi value(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> time[i] >> value[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = t; j >= 0; j--)
		{
			if (j >= time[i])
				dp[i][j] = max(dp[i - 1][j - time[i]] + value[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[m][t] << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}