#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;
const int mod = 1e9 + 7;

int n, q, opt, l1, r1, l2, r2, l, r;
ll val, temp;

struct node
{
	int _left, _right;
	mutable ll _val;
	node(int L = 0, int R = -1, long long V = 0) :_left(L), _right(R), _val(V) {}
	bool operator < (const node& x) const
	{
		return _left < x._left;
	}
}a[N], b[N];

set<node> s;

auto split(int p)//分割
{
	auto iter = s.lower_bound(node(p));
	if (iter != s.end() && iter->_left == p)
		return iter;
	iter--;
	int l = iter->_left;
	int r = iter->_right;
	ll v = iter->_val;

	s.erase(iter);
	s.insert(node(l, p - 1, v));

	return s.insert(node(p, r, v)).first;
}

ll askInterval(int l, int r)//区间和查询
{
	ll ans = 0;
	auto itR = split(r + 1);
	auto itL = split(l);

	for (auto iter = itL; iter != itR; ++iter)
	{
		ans += (ll)(iter->_right - iter->_left + 1) * iter->_val;
		ans %= mod;
	}
	return ans;
}
void intervalAdd(int l, int r, ll v)//区间添加
{
	auto itR = split(r + 1);
	auto itL = split(l);
	for (auto iter = itL; iter != itR; iter++)
	{
		iter->_val += v;
		iter->_val %= mod;
	}
}
void tpInterval(int l, int r, ll v)//推平
{
	auto itR = split(r + 1);
	auto itL = split(l);
	s.erase(itL, itR);
	s.insert(node(l, r, v));
}
void copyInterval(int l1, int r1, int l2, int r2)//复制
{
	auto itR1 = split(r1 + 1);//先切右再切左
	auto itL1 = split(l1);
	int len = 0;
	for (auto iter = itL1; iter != itR1; ++iter)
	{
		a[++len]._left = iter->_left;
		a[len]._right = iter->_right;
		a[len]._val = iter->_val;
	}

	auto itR2 = split(r2 + 1);
	auto itL2 = split(l2);
	s.erase(itL2, itR2);

	for (int i = 1; i <= len; ++i)
	{
		s.insert(node(a[i]._left - l1 + l2, a[i]._right - l1 + l2, a[i]._val));
	}
}

void swapInterval(int l1, int r1, int l2, int r2)//区间交换
{
	if (l1 > l2)
	{
		swap(l1, l2);
		swap(r1, r2);
	}
	int len1 = 0, len2 = 0;
	auto itR1 = split(r1 + 1);
	auto itL1 = split(l1);
	for (auto iter = itL1; iter != itR1; ++iter)
	{
		a[++len1]._left = iter->_left;
		a[len1]._right = iter->_right;
		a[len1]._val = iter->_val;
	}

	auto itR2 = split(r2 + 1);
	auto itL2 = split(l2);
	for (auto iter = itL2; iter != itR2; ++iter)
	{
		b[++len2]._left = iter->_left;
		b[len2]._right = iter->_right;
		b[len2]._val = iter->_val;
	}

	itR1 = split(r1 + 1);
	itL1 = split(l1);
	s.erase(itL1, itR1);

	itR2 = split(r2 + 1);
	itL2 = split(l2);
	s.erase(itL2, itR2);

	for (int i = 1; i <= len2; ++i)
	{
		s.insert(node(b[i]._left - l2 + l1, b[i]._right - l2 + l1, b[i]._val));
	}
	for (int i = 1; i <= len1; ++i)
	{
		s.insert(node(a[i]._left - l1 + l2, a[i]._right - l1 + l2, a[i]._val));
	}
}
void reverseInterval(int l, int r)//区间逆置
{
	if (l > r)
		swap(l, r);
	auto itR = split(r + 1);
	auto itL = split(l);
	int len = 0;
	for (auto iter= itL; iter != itR; ++iter)
	{
		a[++len]._left = iter->_left;
		a[len]._right = iter->_right;
		a[len]._val = iter->_val;
	}
	s.erase(itL, itR);
	for (int i = 1; i <= len; ++i)
	{
		s.insert(node(r - a[i]._right + l, r - a[i]._left + l, a[i]._val));
	}
}


void printKodoriTree()//打印
{
	for (auto it = s.begin(); it != s.end() && it->_right <= n; ++it)
	{
		for (int i = it->_left; i <= it->_right; ++i)
		{
			cout << it->_val << endl;
		}
	}
}


void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)//构建珂朵莉树
	{
		cin >> temp;
		s.insert(node(i, i, temp));
	}
	while (q--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> l >> r;
			cout << askInterval(l, r) << endl;
		}
		else if (opt == 2)
		{
			cin >> l >> r >> val;
			tpInterval(l, r, val);
		}
		else if (opt == 3)
		{
			cin >> l >> r >> val;
			intervalAdd(l, r, val);
		}
		else if (opt == 4)
		{
			cin >> l1 >> r1 >> l2 >> r2;
			copyInterval(l1, r1, l2, r2);
		}
		else if (opt == 5)
		{
			cin >> l1 >> r1 >> l2 >> r2;
			swapInterval(l1, r1, l2, r2);
		}
		else if (opt == 6)
		{
			cin >> l >> r;
			reverseInterval(l, r);
		}
	}
	printKodoriTree();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr);
	solve();
	return 0;
}