#include <iostream>
#include <vector>
#include <algorithm>

#define mod 998244353

typedef long long ll;

using namespace std;

ll a[501];

int main()
{
    a[1] = 1;
    for (int i = 2; i < 501; i++)
    {
        a[i] = a[i - 1] * i % mod;
    }
	int t = 0;
	cin >> t;
	while (t--)
	{
        int num = 0;
        cin >> num;
        if (num % 2 != 0)
            cout << '0' << endl;
        else
            cout << a[num / 2] * a[num / 2] % mod << endl;
	}
	return 0;
}