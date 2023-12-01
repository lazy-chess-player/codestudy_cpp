#include <iostream>
#include <vector>
#include <algorithm>

#define max(a,b) (a)>(b)?(a):(b)

using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> depth(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i > 0)
                depth[i] = a[i] - a[i - 1];
        }
        int maxNum = 0;
        for (int i = n - 2; i > 0; i--)
        {
            while (i > 0 && depth[i] <= 0)
            {
                i--;
            }
            if (i == 0)
            {
                maxNum = a[0];
                break;
            }
            int opNum = k;
            while (opNum > 0)
            {
                
            }
        }
        cout << maxNum << endl;
    }

    return 0;
}