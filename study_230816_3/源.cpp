#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k; 
		ll temp = (ll)pow(2, k);
		if (n % temp == 0)
			cout << n / temp << endl;
		else
			cout << n / temp + 1 << endl;;

	}
	return 0;
}