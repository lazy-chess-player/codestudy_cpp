#include <iostream>
#include <vector>

using namespace std;


signed main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = i + 1;
		}
		if (n == 1)
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] == b[i])
				swap(b[i], b[i + 1]);
		}
		if (a[n - 1] == b[n - 1])
			swap(b[n - 1], b[n - 2]);
		for (int i = 0; i < n; i++)
		{
			cout << b[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}