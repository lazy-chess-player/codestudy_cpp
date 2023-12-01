#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

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
		int ans = nums[0];
		for (auto num : nums)
		{
			ans &= num;
		}
		cout << ans << endl;
	}
	return 0;
}