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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef vector<pss> vpss;
typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef priority_queue<int> pqi;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef unordered_map<int, int> umapii;
typedef unordered_map<string, int> umapsi;

const int N = 1e5 + 5;

void solve()
{
	int n; cin >> n;
	vi a(n), b(n);
	umapii index;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		index[a[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		b[i] = index[b[i]];
	}
	vi vec;
	vec.push_back(b[0]);
	for (int i = 1; i < n; ++i)
	{
		if (vec.back() < b[i]) 
		{
			vec.push_back(b[i]);
			continue;
		}
		auto pos = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
		vec[pos] = b[i];
	}
	cout << vec.size() << endl;
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