#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double f = 3.14;
	cout << "���ȿ���" << setprecision(7)<<setiosflags(ios::fixed) <<f<<endl;
	return 0;
}