#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

//ll n, m;
//ll cnt = 0;
//
//void solve()
//{
//	cin >> n; 
//	string s;
//	cin >> s;
//	unordered_map<char, int> num;
//	vector<int> nums(n);
//	for (int i = n - 1; i >= 0; i--)
//	{
//		num[s[i]]++;
//		nums[i] = num[s[i]] - 1;
//	}
//	for (int i = 0; i < n - 2; i++)
//	{
//		vector<bool> vis(26, false);
//		int rest = n - i - 1;
//		for (int j = i + 1; j < n - 1; j++)
//		{
//			if (s[j] == s[i])
//				continue;
//			if (vis[s[j] - 'a'])
//				continue;
//			if (rest == 0)
//				break;
//			vis[s[j] - 'a'] = true;
//			ll n = nums[j];
//			rest -= n + 1;
//			cnt += ((n + 1) * n) >> 1;
//		}
//	}
//	cout << cnt << endl;
//}

int n;

vector<vector<int>> tree(N);
vector<vector<int>> root(N);
bool isSame[N] = { false };
char colors[N];

bool flag = false;

void bfs(int p)
{
	queue<int> temp;
	temp.push(p);
	while (!temp.empty());
	{
		for (auto x : tree[temp.front()])
		{
			if (tree[x].size() > 2)
			{
				flag = true;
				return;
			}
			if (tree[x].size() == 2)
			{
				if (isSame[x])
				{
					return;
				}
				int sumLeft = tree[tree[x][0]].size();
				int sumRight = tree[tree[x][1]].size();
				if (sumLeft + sumRight == 4)
				{
					flag = true;
					return;
				}
				if (sumLeft + sumRight == 3)
				{

				}
			}
			temp.push(x);
		}
		temp.pop();
	}
}

void solve()
{
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		root[b].push_back(a);
	}
	bfs(1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	//cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}