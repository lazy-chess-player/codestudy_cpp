#include <iostream>
#include <vector>
#include <algorithm>

#define lT p*2
#define rT p*2+1
#define mid (l+r)>>1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e5 + 5;

ll rangeNumST[4 * N]{ 0 };//构建值域数线段树，默认赋值为0
ll a[N];
ll b[N];

void changeNode(int pos, int l, int r, int p)//pos为目标位置，v为目标值
{
	if (l == r)
	{
		rangeNumST[p]++;
		return;
	}
	int m = mid;
	if (pos <= m)
		changeNode(pos, l, m, lT);
	else
		changeNode(pos, m + 1, r, rT);
	rangeNumST[p] = rangeNumST[lT] + rangeNumST[rT];//递归回溯更新
}

ll getSum(int x, int y, int l, int r, int p)
{
	if (x <= l && r <= y)
		return rangeNumST[p];
	int m = mid;
	ll sum = 0;
	if (x <= m)
		sum += getSum(x, y, l, m, lT);
	if (m < y)
		sum += getSum(x, y, m + 1, r, rT);
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	//离散化
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];//使用b数组备份a数组
	}
	sort(b + 1, b + n + 1);//对b数组进行升序排序

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int rank = lower_bound(b + 1, b + n + 1, a[i]) - b;//使用二分统计小于a[i]的值的个数,获得a[i]在数组中的排名
		changeNode(rank, 1, n, 1);//对排名所在的位置加1，表示值域[rank,rank]存在一个元素
		ans += getSum(rank + 1, n, 1, n, 1);//统计值域[rank+1,n]元素数量，加入答案，rank右边元素的数量是比rank先插入且比rank更大的元素的数量，构成逆序对关系
	}
	cout << ans << endl;
	return 0;
}