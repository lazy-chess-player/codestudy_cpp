#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int n, a, b;
int floors[205];
int vis[205];
int ans = INT32_MAX;

void dfs(int x,int sum)
{
	if (x == b)
	{
		ans = min(ans, sum);
	}
	if (vis[x] || sum > ans)
		return;
	vis[x] = 1;
	if (x + floors[x] <= n && !vis[x + floors[x]])
		dfs(x + floors[x], sum + 1);
	if (x - floors[x] > 0 && !vis[x - floors[x]])
		dfs(x - floors[x], sum + 1);
	vis[x] = 0;
}

int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> floors[i];
	}
	dfs(a, 0);
	if (ans != INT32_MAX)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}