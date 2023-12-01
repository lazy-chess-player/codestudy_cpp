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
typedef queue <ll> ql;
typedef queue <pii> qpii;

const int N = 1e5 + 5;

void solve()
{
	int n; cin >> n;
	vpii activitys(n);
	for (int i = 0; i < n; i++)
	{
		cin >> activitys[i].first >> activitys[i].se;
	}
	sort(activitys.begin(), activitys.end(), [](pii a, pii b) {return a.se < b.se; });
	int cnt = 1;
	for (int i = 0, j = i + 1; j < n; j++)
	{
		if (activitys[i].se <= activitys[j].fi)
		{
			cnt++;
			i = j;
		}
	}
	cout << cnt << endl;
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