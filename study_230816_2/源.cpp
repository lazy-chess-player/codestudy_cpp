#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	ll t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		vector<int>buckets(n);
		ll totalStones = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> buckets[i];
			totalStones += buckets[i];
		}
		ll average = totalStones / n;
		if (n == 0)
			cout << totalStones << endl;
		else
		{
			ll ans = 0;
			for (int i = 0; i < n; i++)
			{
				if (buckets[i] < average)
					continue;
				else
					ans += buckets[i] - average;
			}
			cout << ans << endl;
		}
	}
	return 0;
}