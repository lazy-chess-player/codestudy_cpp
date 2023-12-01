#include <bitset>

using namespace std;

const int N = 1e5;

bitset<N> pri;

int primes[N];
int p = 0;

void EulerSieve(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!pri[i])
			primes[++p] = i;
		for (int j = 1; primes[j] * i <= n; ++j)
		{
			pri[primes[j] * i] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
}

int main()
{
	int a = 0, b = 0;
	return 0;
}