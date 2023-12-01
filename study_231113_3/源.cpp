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

const int N = 5e6 + 5;

int scores[N]{ 0 };
int deff[N]{ 0 };

void solve()
{
	int n, q; cin >> n >> q;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> scores[i];
		deff[i] = scores[i] - scores[i - 1];
	}
	int x, y, z;
	while (q--)
	{
		cin >> x >> y >> z;
		deff[x] += z;
		deff[y + 1] -= z;
	}
	int ans = INT32_MAX;
	for (int i = 1; i <= n; i++)
	{
		scores[i] = deff[i] + scores[i - 1];
		if (ans > scores[i])
			ans = scores[i];
	}
	cout << ans;
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