#include<iostream>
#include<algorithm>

using namespace std;

int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n >> s;
		int mx = -1;
		int sum_b = 0;
		for (int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			sum_b += b;
			mx = mx > b ? mx : b;
		}
		int sum = sum_b + s;
		int f = (int)sqrt(double(sum * 2));
		int total = f * (f + 1) / 2;
		if (total == sum && f >= mx)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}