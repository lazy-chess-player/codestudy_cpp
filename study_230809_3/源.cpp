#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long f(long long num)
{
    long long ans = 1;
    while (num)
    {
        ans *= (num % 10);
        ans %= (long long)(1e9 + 7);
        num /= 10;
    }
    return ans;
}

void fun()
{
    long long a, b;
    cin >> a >> b;
    if (b - a > 9)
    {
        cout << 0 << endl;
        return;
    }

    long long result = 1;
    for (long long i = a; i <= b; i++)
    {
        result *= f(i);
        result %= (long long)1e9 + 7;
    }
    cout << result << endl;
    return;
}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        fun();
    }
    return 0;
}
