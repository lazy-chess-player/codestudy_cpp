#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <cmath>
#include <bitset>
#include<stack>


using namespace std;
using ll = long long;
#define LF(x) fixed << setprecision(x)
typedef pair<int, int> pii;
#define endl "\n"

void solve() {

	int n;
	cin >> n;
	vector<int>num1(n);
	vector<int>num2(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> num1[i] >> num2[i];
	}
	for (int i = 1; i < n; i++) 
	{
		if(num1[i] >= num1[0] && num2[i] >= num2[0])
		{
			cout << -1 << endl;
			return;
		}
	}
	cout << num1[0] << endl;
	return;

}


int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}