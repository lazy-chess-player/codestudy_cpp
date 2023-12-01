#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int limit = 10000;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int num = 2; num * num <= limit; ++num)
    {
        if (is_prime[num])
        {
            for (int multiple = num * num; multiple <= limit; multiple += num)
            {
                is_prime[multiple] = false;
            }
        }
    }
    vector<int> primes;
    for (int num = 2; num <= limit; ++num)
    {
        if (is_prime[num])
        {
            primes.push_back(num);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        ans[0] = 1;
        int psz = primes.size();
        int k = 0;
        for (int i = 1; i < psz; i++)
        {
            int j = i + 1;
            for (; j < primes[k]; j++)
            {
                if (ansmp[j] == 0)
                {
                    if(gcd)
                }
                else
                    continue;
            }
        }
        for (auto num : ans)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
