#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define fi first
#define se second
#define endl '\n'

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;
typedef vector<vi> vvi;

typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef queue <psi> qpsi;

typedef priority_queue<int> pqi;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;

typedef unordered_map<int, int> umapii;
typedef unordered_map<string, int> umapsi;

void solve()
{
	int len, n; cin >> len >> n;
	vi v(n + 1);
	vi f(len + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n && i <= len; i++)
	{
		for (int j = i; j <= len; j++)
		{
			f[j] = max(f[j - i] + v[i], f[j]);
		}
	}
	cout << f[len] << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}