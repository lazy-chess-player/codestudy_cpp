#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int a, b = 0;
		cin >> a >> b;
		int diff = abs(a - b);
		int i = 1;
		int ans,sum = 0;
		while (sum + i < diff)
		{
			sum += i;
			i++;
		}
		ans = i + diff % 2;//如果diff为奇数，则需要额外的一次操作数
		cout << ans << endl;
	}
	return 0;
}