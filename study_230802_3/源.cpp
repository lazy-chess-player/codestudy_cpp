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
		ll num = 0;
		cin >> num;
		bool flag = false;
		for (ll i = 1; i <= cbrt(num); i++)
		{
			ll remainder = num - i*i*i;
			ll temp = cbrt(remainder);
			if (temp * temp * temp == remainder && temp > 0)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}