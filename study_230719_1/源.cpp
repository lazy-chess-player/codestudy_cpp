#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
inline bool cmp(const p& a, const p& b)
{
     return a.first > b.first;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<p> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i].first;
		nums[i].second = i+1;
	}
	sort(nums.begin(), nums.end(),cmp);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (i)*nums[i].first + 1;
	}
	cout << ans << endl;
	for (auto pa: nums)
	{
		cout << pa.second << ' ';
	}
	return 0;
}