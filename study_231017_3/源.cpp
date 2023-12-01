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
	int needMilk, n;
	cin >> needMilk >> n;
	vpii farmers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> farmers[i].fi >> farmers[i].se;
	}
	sort(farmers.begin(), farmers.end(), [](pii a, pii b) {return a.first < b.fi; });
	int i = 0;
	int cost = 0;
	while (i < n && needMilk)
	{
		if (needMilk < farmers[i].se)
		{
			cost += needMilk * farmers[i].fi;
			needMilk = 0;
		}
		else
		{
			cost += farmers[i].se * farmers[i].fi;
			needMilk -= farmers[i].se;
		}
		i++;
	}
	cout << cost << endl;
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