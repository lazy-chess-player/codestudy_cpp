//#include<iostream>
//int main()
//{
//    int n = 0;
//    std::cin >> n;
//    int num = 0;
//    int max = 0;
//    for (int  i = 0; i < n; i++)
//    {
//        int a = 0, b = 0;
//        std::cin >> a >> b;
//        num += (b - a);
//        max = num > max ? num : max;
//    }
//    std::cout<<max;
//    return 0;
//}

//#include <iostream>
//
//int main()
//{
//    long long k = 0, l = 0;
//    std::cin >> k >> l;
//    int cnt = 0;
//    while (cnt < 32)
//    {
//        if (l == k)
//            break;
//        else
//            k *= k;
//    }
//    if (cnt < 32)
//    {
//        std::cout << "YES" << std::endl;
//        std::cout << cnt << std::endl;
//    }
//    else
//    {
//        std::cout << "NO" << std::endl;
//    }
//    return 0;
//}

//#include <iostream>
//
//int main() 
//{
//    int n = 0;
//    std::cin >> n;
//    long long sum = 0; 
//    for (int i = 1; i < n+1; i++)
//    {
//        int ai =0;
//        std::cin >> ai;
//        sum += (ai - 1) * i;
//    }
//    sum+=n;
//    std::cout << sum << std::endl;
//    return 0;
//}

//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//#include <string >
//#include <vector>
//#include <cmath>
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<long long>Nums(n + 1);
//	vector<long long>Sum(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> Nums[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//
//		Sum[i] = (i) * (Nums[i] - 1) + 1 + Sum[i - 1];//对于第i个问题，需要试错Nums[i]-1次，每次需要重做i-1道题，所以有该式子
//
//	}
//	cout << Sum[n];
//
//	return 0;
//}

#include<iostream>
#include <string>

using namespace std;

bool is_super_lucky(long long x) 
{
    int count_4 = 0, count_7 = 0;
    while (x > 0) 
    {
        int digit = x % 10;
        if (digit == 4) 
        {
            count_4++;
        }
        else if (digit == 7) 
        {
            count_7++;
        }
        else 
        {
            return false;
        }
        x /= 10;
    }
    return count_4 == count_7;
}

long long generate_super_lucky(int len) 
{
    long long result = 0;
    for (int i = 0; i < len; i++) 
    {
        result = result * 10 + (i % 2 == 0 ? 4 : 7);
    }
    return result;
}

int main() 
{
    long long n;
    cin >> n;
    for (int len = 1; len <= 20; len++) 
    {
        long long x = generate_super_lucky(len);
        if (x >= n && is_super_lucky(x)) 
        {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}
