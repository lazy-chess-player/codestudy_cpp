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

const int N = 39 + 5;

int arr[N][N]{ 0 };
int n;

void printArr()
{
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j];
			if (j != n)
				cout << ' ';
			else
				cout << endl;
		}
}

void solve()
{
	cin >> n;
	int x = 1, y = (n + 1) / 2;
	arr[x][y] = 1;//��ʼֵx yΪһ��һ�� 
	for (int i = 2; i <= n * n; i++)
	{
		if (x == 1 && y != n)//����1
			x = n, y++;
		else if (x != 1 && y == n)//����2
			x--, y = 1;
		else if (x == 1 && y == n)//����3
			x++;
		else if (!arr[x - 1][y + 1])//����4
			x--, y++;
		else
			x++;
		arr[x][y] = i;
	}
	printArr();
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