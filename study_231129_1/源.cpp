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

const int MAXN = 5e2 + 5;


double d1 = 0.0;
double c = 0.0;
double d2 = 0.0;
double p = 0.0;
int n = 0;
double cost = 0.0;
double run = 0.0;

double d[MAXN];
double v[MAXN];

void solve()
{
	cin >> d1 >> c >> d2 >> p >> n;
	d[0] = 0.0;
	v[0] = p;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> v[i];
	}

	bool falg = false;

	double oil = c;
	double can = 0.0;
	int i = 0;

	while (oil > 0 && run < d1)
	{
		can = oil * d2;
		double now = 0.0;
		double less = 0x3f3;
		while (now < can)
		{
			now += d[++i];
			oil -= d[i];
		}
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