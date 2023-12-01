#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    string s;
        int r, l;
        bool flag = 0;
        cin >> s;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                r = i + 1;
                l = i + 2;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            cout << r << ' ' << l << endl;
        }
        else 
            cout<<"NO"<<endl;
    return 0;
}