#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int sum[4 * N]{ 0 };//区间和线段树
int tag[4 * N]{ 0 };//延迟节点
int minNum[4 * N]{ 0 };//最小值线段数
int nums[N];

void build(int l, int r, int p)//l为当前左边界，r为当前右边界,p为线段树当前节点的索引
{
	//如果l和r相等，表示已经到了叶节点，直接返回。
	if (l == r)
	{
		sum[p] = nums[l];
		return;
	}
	//二分递归建树
	int mid = (l + r) / 2;
	build(l, mid, p * 2);
	build(mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

void buildMinNum(int l, int r, int p)//l为当前左边界，r为当前右边界,p为线段树当前节点的索引
{
	//如果l和r相等，表示已经到了叶节点，直接返回。
	if (l == r)
	{
		sum[p] = nums[l];
		return;
	}
	//二分递归建树
	int mid = (l + r) / 2;
	buildMinNum(l, mid, p * 2);
	buildMinNum(mid + 1, r, p * 2 + 1);
	sum[p] = min(sum[p * 2], sum[p * 2 + 1]);
}


void checkDelay(int l, int r, int p, char opt = '=')//检测函数，检查当前节点是否有延迟标记，有则传递给子树
{
	if (!tag[p])
		return;
	int mid = (l + r) / 2;
	if (opt == '=')
	{
		tag[p * 2] = tag[p * 2 + 1] = tag[p];
		sum[p * 2] = (mid - l + 1) * tag[p];
		sum[p * 2 + 1] = (r - mid) * tag[p];
	}
	else if (opt == '+')
	{
		tag[p * 2] += tag[p];
		tag[p * 2 + 1] += tag[p];
		sum[p * 2] += (mid - l + 1) * tag[p];
		sum[p * 2 + 1] += (r - mid) * tag[p];
	}
	tag[p] = 0;
}

ll getSum(int x, int y, int l, int r, int p)//x,y为待查询区间[x,y]的左右边界
{
	if (x <= l && r <= y)//如果当前节点被包含，直接返回当前节点的值
		return sum[p];
	checkDelay(l, r, p);
	int mid = (l + r) / 2;
	ll sum = 0;
	if (x <= mid)//中间值大于等于左边界，表示左半界需要查询
		sum += getSum(x, y, l, mid, p * 2);
	if (mid < y)//中间值小于右边界，表示右边界需要查询，等于则表示没有右半界了
		sum += getSum(x, y, mid + 1, r, p * 2 + 1);
	return sum;
}

int getMin(int x, int y, int l, int r, int p)//x,y为待查询区间[x,y]的左右边界
{
	if (x <= l && r <= y)//如果当前节点被包含，直接返回当前节点的值
		return minNum[p];
	checkDelay(l, r, p);
	int mid = (l + r) / 2;
	int mn = 0;
	if (x <= mid)//中间值大于等于左边界，表示左半界需要查询
		mn = min(mn, getMin(x, y, l, mid, p * 2));
	if (mid < y)//中间值小于右边界，表示右边界需要查询，等于则表示没有右半界了
		mn = min(mn,getMin(x, y, mid + 1, r, p * 2 + 1));
	return mn;
}

void changeNode(int pos, int v, int l, int r, int p)//pos为目标位置，v为目标值
{
	if (l == r)
	{
		sum[p] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)//pos在左子树
		changeNode(pos, v, l, mid, p * 2);
	else//pos在右子树
		changeNode(pos, v, mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];//递归回溯更新
}

void changeInterval(int x, int y, int v, int l, int r, int p)
{
	if (x <= l && r <= y)
	{
		tag[p] = v;
		sum[p] = v * (r - l + 1);
		return;
	}
	checkDelay(l, r, p);
	int mid = (l + r) / 2;
	if (x <= mid)
		changeInterval(x, y, v, l, mid, p * 2);
	if (mid <= y)
		changeInterval(x, y, v, mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

void addInterval(int x, int y, int v, int l, int r, int p)
{
	if (x <= l && r <= y)
	{
		tag[p] += v;
		sum[p] += v * (r - l + 1);
		return;
	}
	checkDelay(l, r, p, '+');
	int mid = (l + r) / 2;
	if (x <= mid)
		addInterval(x, y, v, l, mid, p * 2);
	if (mid <= y)
		addInterval(x, y, v, mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	build(1, n, 1);
	return 0;
}