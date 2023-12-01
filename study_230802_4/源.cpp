#include <iostream>
#include <vector>

using namespace std;

void structTree( vector<int>& arr, vector<int>& depth, int left, int right, int currDepth)
{
    if (left > right)
    {
        return;
    }

    int maxIdx = left;
    for (int i = left + 1; i <= right; ++i)
    {
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    }

    depth[maxIdx] = currDepth;

    structTree(arr, depth, left, maxIdx - 1, currDepth + 1);
    structTree(arr, depth, maxIdx + 1, right, currDepth + 1);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        vector<int> depth(n, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        structTree(arr, depth, 0, n - 1, 0);

        for (int d : depth)
        {
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}
