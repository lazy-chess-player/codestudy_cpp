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

ll rangeNumST[4 * N]{ 0 };//����ֵ�����߶�����Ĭ�ϸ�ֵΪ0
ll a[N];
ll b[N];

void changeNode(int pos, int l, int r, int p)//posΪĿ��λ�ã�vΪĿ��ֵ
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
	rangeNumST[p] = rangeNumST[lT] + rangeNumST[rT];//�ݹ���ݸ���
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
	
	//��ɢ��
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];//ʹ��b���鱸��a����
	}
	sort(b + 1, b + n + 1);//��b���������������

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int rank = lower_bound(b + 1, b + n + 1, a[i]) - b;//ʹ�ö���ͳ��С��a[i]��ֵ�ĸ���,���a[i]�������е�����
		changeNode(rank, 1, n, 1);//���������ڵ�λ�ü�1����ʾֵ��[rank,rank]����һ��Ԫ��
		ans += getSum(rank + 1, n, 1, n, 1);//ͳ��ֵ��[rank+1,n]Ԫ������������𰸣�rank�ұ�Ԫ�ص������Ǳ�rank�Ȳ����ұ�rank�����Ԫ�ص���������������Թ�ϵ
	}
	cout << ans << endl;
	return 0;
}