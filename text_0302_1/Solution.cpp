#include "Solution.h"
int main()
{
	double num = 0.0;
	cin >> num;
	string ans = new char[33];
	Solution e1;
	ans = e1.printBin(num);
	cout << (num) << endl;
	delete[] &ans;
	return 0;
}