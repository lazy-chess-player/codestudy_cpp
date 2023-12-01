#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;

struct node
{
	int _left, _right;
	mutable ll _val;
	bool operator < (const node& x) const
	{
		return _left < x._left;
	}
	node()
	{
		_left = 0, _right = 0, _val = 0;
	}
	node(int left, int right, ll val)
	{
		_left = left, _right = right, _val = val;
	}
}a[N], b[N];

set<node> kt;

auto split(int pos)
{
	auto it = kt.lower_bound(node(pos, 0, 0));
	if (it != kt.end() && it->_left == pos)
		return it;
	it--;
	int left = it->_left;
	int right = it->_right;
	ll val = it->_val;
	kt.erase(it);
	kt.insert(node(left, pos - 1, val));
	return kt.insert(node(pos, right, val)).first;
}

void assign(int l, int r, ll v)
{
	auto itR = split(r + 1);
	auto itL = split(l);
	kt.erase(itL, itR);
	kt.insert({ l,r,v });
}

ll sumLtoR(int l, int r)
{
	ll ans = 0;
	auto itR = split(r + 1);
	auto itL = split(l);
	for (auto it = itL; it != itR; it++)
	{
		ans += 1LL*(it->_val) * (it->_right - it->_left + 1);
		ans %= MOD;
	}
	return ans;
}

void tp(int l, int r, ll v)
{
	auto itR = split(r + 1);
	auto itL = split(l);
	kt.erase(itL, itR);
	kt.insert(node(l, r, v));
}

void addLtoR(int l, int r, ll v)
{
	auto itR = split(r + 1);
	auto itL = split(l);
	for (auto it = itL; it != itR; it++)
	{
		it->_val += v;
		it->_val %= MOD;
	}
}

void copy(int l1, int r1, int l2, int r2)
{
	auto itR1 = split(r1 + 1);
	auto itL1 = split(l1);
	auto itR2 = split(r2 + 1);
	auto itL2 = split(l2);
	kt.erase(itL2, itR2);
	for (auto it = itL1; it != itR1; it++)
	{
		kt.insert({ l2 + it->_left - l1,l2 + it->_right - l1,it->_val });
	}
}

void swap(int l1, int r1, int l2, int r2)
{
	auto itR1 = split(r1 + 1);
	auto itL1 = split(l1);
	auto itR2 = split(r2 + 1);
	auto itL2 = split(l2);
	int len1 = 0, len2 = 0;
	for (auto it = itL1; it != itR1; it++)
	{
		a[++len1] = *it;
	}
	for (auto it = itL2; it != itR2; it++)
	{
		b[++len2] = *it;
	}
	kt.erase(itL1, itR1);
	kt.erase(itL2, itR2);
	for (int i = 1; i <= len1; i++)
	{
		kt.insert({ l2 + a[i]._left - l1,l2 + a[i]._right - l1,a[i]._val});
	}
	for (int i = 1; i <= len2; i++)
	{
		kt.insert({ l1 + b[i]._left - l2,l1 + b[i]._right - l2,b[i]._val });
	}
}

void reverse(int l, int r)
{
	auto itR = split(r + 1);
	auto itL = split(l); 
	int len = 0;
	for (auto it = itL; it != itR; it++)
	{
		a[++len] = *it;
	}
	kt.erase(itL, itR);
	for (int i = len; i > 0; i--)
	{
		kt.insert(node(l + r - a[i]._right, l + r - a[i]._left, a[i]._val));
	}
}

void write()
{
	for (auto it = kt.begin(); it != kt.end(); it++)
	{
		for (int i = it->_left; i <= it->_right; i++)
		{
			cout << it->_val << ' ';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m, num, op, l, r, v, l1, r1, l2, r2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		kt.insert(node(i, i, num));
	}
	while (m--)
	{
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> l >> r;
			cout << sumLtoR(l, r) << endl;
			break;
		case 2:
			cin >> l >> r >> v;
			tp(l, r, v);
			break;
		case 3:
			cin >> l >> r >> v;
			addLtoR(l, r, v);
			break;
		case 4:
			cin >> l1 >> r1 >> l2 >> r2;
			copy(l1, r1, l2, r2);
			break;
		case 5:
			cin >> l1 >> r1 >> l2 >> r2;
			swap(l1, r1, l2, r2);
			break;
		case 6:
			cin >> l >> r;
			reverse(l, r);
			break;
		default:
			break;
		}
	}
	write();cout << endl;
	return 0;
}