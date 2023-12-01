#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

typedef long long ll;

const int N = 500010;
const int mod = 1e9 + 7;

int n, q, op, l1, r1, l2, r2, l, r;
ll val, x;

inline int read()
{
	register int x = 0, y = 1; 
	register char ch = getchar();
	while (ch > '9' || ch < '0') 
	{
		if (ch == '-')
			y = -1;
		ch = getchar(); 
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar(); 
	}
	return x * y;
}
struct node
{
	int _left, _right;
	mutable long long _val;
	node(int L = 0, int R = -1, long long V = 0) :_left(L), _right(R), _val(V) {}
	bool operator < (const node& x) const 
	{
		return _left < x._left; 
	}
} a[N], b[N];

set<node>s;

auto split(int pos)
{
	auto it = s.lower_bound(node(pos));
	if (it != s.end() && it->_left == pos)
		return it;
	it--;
	int l = it->_left;
	int r = it->_right;
	ll v = it->_val;

	s.erase(it);
	s.insert(node(l, pos - 1, v));

	return s.insert(node(pos, r, v)).first;
}

ll askInterval(int l, int r)
{
	ll ans = 0;
	auto itR = split(r + 1);
	auto itL = split(l);

	for (auto it = itL; it != itR; ++it)
	{
		ans += (ll)(it->_right - it->_left + 1) * it->_val;
		ans %= mod;
	}
	return ans;
}

void intervalAdd(int l, int r, ll v)
{
	auto itR = split(r + 1);
	auto itL = split(l);
	for (auto it = itL; it != itR; ++it)
	{
		it->_val += v;
		it->_val %= mod;
	}
}
void tpInterval(int l, int r, ll v)
{
	auto itR = split(r + 1);
	auto itL = split(l);
	s.erase(itL, itR);
	s.insert(node(l, r, v));
}
void copyInterval(int l1, int r1, int l2, int r2)
{
	auto itR1 = split(r1 + 1);
	auto itL1 = split(l1);
	int len = 0;
	for (auto it = itL1; it != itR1; ++it)
	{
		a[++len]._left = it->_left;
		a[len]._right = it->_right;
		a[len]._val = it->_val;
	}

	auto itR2 = split(r2 + 1);
	auto itL2 = split(l2);
	s.erase(itL2, itR2);

	for (int i = 1; i <= len; ++i)
	{
		s.insert(node(a[i]._left - l1 + l2, a[i]._right - l1 + l2, a[i]._val));
	}
}

void printKodoriTree()
{
	for (auto it = s.begin(); it != s.end() && it->_right <= n; ++it)
	{
		for (int i = it->_left; i <= it->_right; ++i)
		{
			printf("%lld ", it->_val);
		}
	}
}

void swapInterval(int l1, int r1, int l2, int r2)
{
	if (l1 > l2)
	{
		swap(l1, l2); 
		swap(r1, r2);
	}
	int len1 = 0, len2 = 0;
	auto itR1 = split(r1 + 1);
	auto itL1 = split(l1);
	for (auto it = itL1; it != itR1; ++it)
	{
		a[++len1]._left = it->_left;
		a[len1]._right = it->_right;
		a[len1]._val = it->_val;
	}

	auto itR2 = split(r2 + 1);
	auto itL2 = split(l2);
	for (auto it = itL2; it != itR2; ++it)
	{
		b[++len2]._left = it->_left;
		b[len2]._right = it->_right;
		b[len2]._val = it->_val;
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


void reverseInterval(int l, int r)
{
	if (l > r)
		swap(l, r);
	auto itR = split(r + 1);
	auto itL = split(l);
	int len = 0;
	for (auto it = itL; it != itR; ++it)
	{
		a[++len]._left = it->_left;
		a[len]._right = it->_right;
		a[len]._val = it->_val;
	}
	s.erase(itL, itR);
	for (int i = 1; i <= len; ++i)
	{
		s.insert(node(r - a[i]._right + l, r - a[i]._left + l, a[i]._val));
	}
}
int main()
{
	n = read(), q = read();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &x);
		s.insert(node(i, i, x));
	}
	s.insert((node)(n + 1, n + 1, (ll)0));
	while (q--)
	{
		op = read();
		if (op == 1)
		{
			l = read(); r = read();
			printf("%lld\n", askInterval(l, r));
		}
		if (op == 2)
		{
			l = read(); r = read(); scanf("%lld", &val);
			tpInterval(l, r, val);
		}
		if (op == 3)
		{
			l = read(); r = read(); scanf("%lld", &val);
			intervalAdd(l, r, val);
		}
		if (op == 4)
		{
			l1 = read(); r1 = read(); l2 = read(); r2 = read();
			copyInterval(l1, r1, l2, r2);
		}
		if (op == 5)
		{
			l1 = read(); r1 = read(); l2 = read(); r2 = read();
			swapInterval(l1, r1, l2, r2);
		}
		if (op == 6)
		{
			l = read(); r = read();
			reverseInterval(l, r);
		}
	}
	printKodoriTree();
	return 0;
}