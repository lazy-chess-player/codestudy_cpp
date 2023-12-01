#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//        vector<pi> segments;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> segments[i].first >> segments[i].second;
//        }
//
//    }
//}

int main()
{
    int t;
    cin >> t;
    pi p;
    while (t--)
    {
        int n;
        cin >> n;
        vector <pi> seg(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> seg[i].first >> seg[i].second;
        }
		long long n;
		cin >> n;
		for (long long i = 0; i < n; i++)
		{
			cin >> c[i].a >> c[i].b;

		}
		sort(c, c + n, cmp);
		while (!q.empty())
		{
			q.pop();
		}

		long long min = 0;
		long long sum = 0;
		min = c[0].a;
		int i = 0;
		while (1)
		{
			while (i < n && min >= c[i].a)
			{
				q.push(c[i].b);
				++i;
			}

			while (!q.empty() && q.top() < min)
			{
				q.pop();
			}
			if (q.empty())
			{
				if (i >= n)
				{
					break;
				}
				else
				{
					min = c[i].a;
				}
			}
			else
			{
				min++;
				q.pop();
				sum++;
			}
			}

		return 0;
    }
}