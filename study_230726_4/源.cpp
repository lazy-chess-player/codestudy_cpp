#include <iostream>
#include <string>
#include <vector>

using namespace std;

void flip_bit(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = s[i] - 48 ? '0' : '1';
	}
	return;
}

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> op(n);
		if (k % 2)
		{
			flip_bit(s);
		}
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0' && k > 0)
			{
				s[i]++;
				op[i]++;
				k--;
			}
		}
		if (k % 2)
			s[n - 1] = '0';
		if (k > 0)
			op[n - 1] += k;
		cout << s << endl;
		for (int i = 0; i < n; i++)
		{
			cout << op[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}