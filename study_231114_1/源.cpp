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

const int N = 2e5 + 5;

ll diff
[N]{ 0 };
ll a[N]{ 0 };

ll n, q, s, t;

ll cal(ll x) { return x > 0 ? -s * x : -t * x; }

void solve()
{
	cin >> n >> q >> s >> t;
	ll last = 0;
	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
		diff[i] = a[i] - last;
		last = a[i];
		ans += cal(diff[i]);
	}
	ll x, y, z;
	while (q--)
	{
		cin >> x >> y >> z;
		ans -= cal(diff[x]);
		diff[x] += z;
		ans += cal(diff[x]);
		if (y != n)
		{
			ans -= cal(diff[y + 1]); 
			diff[y + 1] -= z;
			ans += cal(diff[y + 1]);
		}
		cout << ans << endl;
	}
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