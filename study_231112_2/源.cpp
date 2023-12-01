#include <iostream>
#include <algorithm>

#define ls p*2
#define rs p*2+1
#define mid (l+r)>>1

using namespace std;

typedef long long ll;

const int N = 5e4 + 5;

int maxST[4 * N]{ 0 };
int minST[4 * N]{ 0 };
int nums[N]{ 0 };

void buildSumST(int l, int r, int p)
{
	if (l == r)
	{
		maxST[p] = nums[l];
		minST[p] = nums[l];
		return;
	}
	int m = mid;
	buildSumST(l, m, ls);
	buildSumST(m + 1, r, rs);
	maxST[p] = max(maxST[ls], maxST[rs]);
	minST[p] = min(minST[ls], minST[rs]);
}


int getMax(int x, int y, int l, int r, int p)
{
	if (x <= l && r <= y)
		return maxST[p];
	int m = mid; 
	int maxNum = INT32_MIN;
	if (x <= m)
		maxNum= max(maxNum,getMax(x, y, l, m, p * 2));
	if (m < y)
		maxNum = max(maxNum, getMax(x, y, m + 1, r, p * 2 + 1));
	return maxNum;
}
int getMin(int x, int y, int l, int r, int p)
{
	if (x <= l && r <= y)
		return minST[p];
	int m = mid; 
	int minNum = INT32_MAX;
	if (x <= m)
		minNum= min(minNum,getMin(x, y, l, m, p * 2));
	if (m < y)
		minNum = min(minNum, getMin(x, y, m + 1, r, p * 2 + 1));
	return minNum;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> nums[i];
	buildSumST(1, n, 1);
	int x, y;
	while (m--)
	{
		cin >> x >> y;
		int mx = getMax( x,y,1,n,1 );
		int mn = getMin( x,y,1,n,1 );
		cout << mx - mn << endl;
	}
	return 0;
}