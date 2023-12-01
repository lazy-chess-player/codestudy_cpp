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
#include <bitset>
#include <cmath>

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

const int N = 5e3 + 5;
const int mod = 80112002;

int n, m;
int in[N], out[N];

vector<int> chain[N];

queue<int> q;
int ans;
int num[N];


void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a , b;
		cin >> a >> b;
		in[b]++;
		out[a]++;
		chain[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!in[i])
		{
			num[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int start = q.front(); 
		q.pop();
		int len = chain[start].size();
		for (int i = 0; i < len; i++)
		{
			int next = chain[start][i];
			in[next]--;
			num[next] = (num[next] + num[start]) % mod;
			if (in[next] == 0)
				q.push(chain[start][i]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!out[i])
			ans = (ans + num[i]) % mod;
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