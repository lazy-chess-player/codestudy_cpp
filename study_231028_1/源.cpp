#include <iostream>

using namespace std;

int main()
{
	int a, b;
	int maxTime = 0;
	int maxIndex = -1;
	for (int i = 0; i < 7; i++)
	{
		cin >> a >> b;
		int sumTime =a + b;
		if (sumTime > 8 && sumTime > maxTime)
		{
			maxTime = sumTime;
			maxIndex = i;
			if (maxIndex != -1)
				cout << maxIndex + 1 << endl;
		}
	}
	return 0;
}