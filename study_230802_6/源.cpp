#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> nmap1;
        unordered_map<int, int> nmap2;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            nmap1[arr[i]]++;
        }
        for (auto n:nmap1)
        {
            nmap2[n.second]++;
        }
        int min = 0;
        for (auto x:nmap2)
        {

        }
    }
    return 0;
}
