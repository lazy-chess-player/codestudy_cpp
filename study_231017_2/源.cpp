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
	int w, g;
	cin >> w;
	cin >> g;
	vi souvenirs(g);
	for (int i = 0; i < g; i++)
	{
		cin >> souvenirs[i];
	}
	sort(souvenirs.begin(), souvenirs.end());
	int l = 0, r = souvenirs.size() - 1;
	int cnt = 0;
	while (l<=r)
	{
		if (l == r)
		{
			cnt++;
			break;
		}
		if(souvenirs[l] + souvenirs[r] <= w)
		{
			cnt++;
			l++;
			r--;
		}
		else
		{
			cnt++;
			r--;
		}
	}
	cout << cnt << endl;
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