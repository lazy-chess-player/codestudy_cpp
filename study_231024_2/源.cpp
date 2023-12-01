#include <iostream>

#define lT p*2
#define rT p*2+1
#define mid (l+r)>>1

using namespace std;

const int N = (int)1e5 + 5;

int nums[N];

struct segeTree
{
	int l, r;
	int len;
	int sum1,max1,left1,right1;
	int sum0,max0,left0,right0;
	int cov, rev;
} st[4 * N];

void operateRange(int p, int opt)
{
	segeTree& t = st[p];
	switch (opt)
	{
	case 0:
		t.sum1 = t.left1 = t.right1 = t.max1 = 0;
		t.sum0 = t.left0 = t.right0 = t.max0 = t.len;
		t.cov = 0;
		t.rev = 0;
		break;
	case 1:
		t.sum1 = t.left1 = t.right1 = t.max1 = t.len;
		t.sum0 = t.left0 = t.right0 = t.max0 = 0;
		t.cov = 1;
		t.rev = 0;
		break;
	case 2:
		swap(t.sum0, t.sum1);
		swap(t.left0, t.left1);
		swap(t.right0, t.right1);
		swap(t.max0, t.max1);
		t.rev ^= 1;
		break;
	default:
		break;
	}
}

void pushUp(segeTree& t, const segeTree& L, const segeTree& R)
{
	t.l = L.l;
	t.r = R.r;
	t.len = L.len + R.len;
	t.cov = -1;
	t.rev = 0;
	t.sum0 = L.sum0 + R.sum0;
	t.sum1 = L.sum1 + R.sum1;
	t.left1 = L.sum0 ? L.left1 : L.left1 + R.left1;
	t.left0 = L.sum1 ? L.left1 : L.left0 + R.left0;
	t.right1 = R.sum0 ? R.right1 : R.right1 + L.right1;
	t.right0 = R.sum1 ? R.right0 : R.right0 + L.right0;
	t.max1 = max(max(L.max1, R.max1), L.right1 + R.left1);
	t.max0 = max(max(L.max0, R.max0), L.right0 + R.left0);
}
void pushDown(int p)
{
	segeTree& t = st[p];
	if (t.cov != -1)
	{
		operateRange(lT, t.cov);
		operateRange(rT, t.cov);
	}
	if (t.rev)
	{
		operateRange(lT, 2);
		operateRange(rT, 2);
	}
	t.cov = -1;
	t.rev = 0;
}

void changeRange(int x, int y, int p, int k)
{
	if (x > st[p].r || y < st[p].l)
		return;
	if (x <= st[p].l && st[p].r <= y)
	{
		operateRange(p, k);
		return;
	}
	changeRange(x, y, lT, k);
	changeRange(x, y, rT, k);
	pushUp(st[p], st[lT], st[rT]);
}

void build(int l, int r, int p)
{
	if (l == r)
	{
		int i = nums[l];
		st[p] = { l,r,l - r + 1,i,i,i,i,i ^ 1,i ^ 1,i ^ 1,i ^ 1,-1,0 };
		return;
	}
	int m = mid;
	build(l, m, lT);
	build(m + 1, r, rT);
	pushUp(st[p], st[lT], st[rT]);
}

segeTree query(int x, int y, int p)
{
	if (x > st[p].r || y < st[p].l)
		return {};
	if (x <= st[p].l && st[p].r <= y)
		return st[p];
	pushDown(p);
	segeTree T;
	pushUp(T, query(x, y, lT), query(x, y, rT));
	return T;
}

int main()
{
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> nums[i];
	build(1, n, 1);
	int cmd, x, y;
	while (m--)
	{
		cin >> cmd >> x >> y;
		switch (cmd)
		{
		case 0:
			changeRange(x, y, 1, cmd);
			break;
		case 1:
			changeRange(x, y, 1, cmd);
			break;
		case 2:
			changeRange(x, y, 1, cmd);
			break;
		case 3:
			segeTree t1 = query(x, y, 1);
			cout << t1.sum1 + 1 << endl;
			break;
		case 4:
			segeTree t2 = query(x, y, 1);
			cout << t2.max1 + 1 << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}