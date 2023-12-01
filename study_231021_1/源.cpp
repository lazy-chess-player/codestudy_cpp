#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>

#define max(a,b) (nums)>(b)?(nums):(b)
#define min(a,b) (nums)<(b)?(nums):(b)
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
typedef unordered_map<string, int> umsi;

const int N = 2e5 + 5;

void solveA()
{
	int n, k;
	cin >> n >> k;
	while (k--)
	{
		if (n % 10)
			n--;
		else
			n /= 10;
	}
	cout << n << endl;
}

void solveB()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	umsi strmap;
	for (int i = 1; i < n; i++)
	{
		string temp;
		temp += s[i - 1];
		temp += s[i];
		strmap[temp]++;
	}
	auto ans = max_element(strmap.begin(), strmap.end(), [](auto a, auto b) {return a.se < b.se; });
	cout << (*ans).fi << endl;
}


void solveC()
{
	int n, k;
	cin >> n >> k;
	vi nums(n + 2);
	nums[0] = 1;
	nums[n + 1] = 1000000001;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	if (nums[k] == nums[k + 1])
		cout << -1 << endl;
	else
		cout << nums[k] << endl;
}

typedef struct node
{
	ll val;
	ll three;
	ll two;
} num;

void count2and3(num& x)
{
	ll temp = x.val;
	while (temp % 2 == 0)
	{
		x.two++;
		temp /= 2;
	}
	while (temp % 3 == 0)
	{
		x.three++;
		temp /= 3;
	}
}

void solveD()
{
	int n;
	cin >> n;
	vl sequence(n);
	for (int i = 0; i < n; i++)
		cin >> sequence[i];
	vector<num> nums(n);
	for (int i = 0; i < n; i++)
	{
		nums[i].val = sequence[i];
		count2and3(nums[i]);
	}
	sort(nums.begin(), nums.end(), [](num a, num b) {if (a.three > b.three)return a.three > b.three; else return a.two < b.two; });
	for (auto x : nums)
		cout << x.val << ' ';
	cout << endl;
}

vector<vi> graph(2e5 + 5);
vector<bool> vis(2e5 + 5, false);

bool twoDegree = false;

void dfs(int x)
{
	if (graph[x].size()!= 2)
		twoDegree = false;
	for (auto i : graph[x])
	{
		if (!vis[i])
		{
			vis[i] = true;
			dfs(i);
		}
	}
}


void solveE()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			twoDegree = true;
			dfs(i);
			ans += (int)twoDegree;
		}
	}
	cout << ans<<endl;
}

int nums[N];
int dp[N];
int last[N];
int index[N];
void solveF()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	map<int, int> nmap;
	dp[0] = 1;
	nmap[nums[0]] = 0;
	int ans = 1;
	int ans_i = 0;
	for (int i = 1; i < n; i++)
	{
		nmap[nums[i]] = i;
		if (nmap.find(nums[i] - 1) != nmap.end())
		{
			dp[i] = dp[nmap[nums[i] - 1]] + 1;
			last[i] = nmap[nums[i] - 1];
		}
		else 
		{
			dp[i] = 1;
			last[i] = i;
		}
		if (dp[i] > ans) 
		{
			ans = dp[i];
			ans_i = i;
		}
	}
	cout << ans << endl;
	int j = ans_i;
	int cnt = 0;
	index[cnt++] = ans_i + 1;
	while (last[j] != j)
	{
		j = last[j];
		index[cnt++] = j + 1;
	}
	for (int i = cnt - 1; i >= 0; i--)
		cout << index[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solveF();
	}
	return 0;
}
