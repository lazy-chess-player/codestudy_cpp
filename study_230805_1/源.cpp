#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
        int n;
        cin >> n;
        vector<int> a(n); 
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int mx = 0;
        for (int i = n - 2; i >= 0; --i) 
        {
            while (i >= 0 && a[i] <= a[i + 1])
            {
                i--;
            }
            if (i == -1)
                break;
            mx = a[i] > mx ? a[i] : mx;
        }

        cout << mx << endl;
	}
}