#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int f(int a,int b)
{
	int cnt = 0;
	a *= 2;
	while (a < b)
	{
		a *= 2;
		cnt++;
	}
	return cnt;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		int ans = 0;
		for (int i = 0; i < n-1; i++)
		{
			if (nums[i] > nums[i + 1])
				ans += f(nums[i + 1], nums[i]);
			else if (nums[i] < nums[i + 1])
				ans += f(nums[i], nums[i + 1]);
		}
		cout << ans << endl;
	}
	return 0;
}