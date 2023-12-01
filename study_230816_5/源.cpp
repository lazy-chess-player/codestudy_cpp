#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll k;
        string s;
        ll n, m;
        cin >> n >> s >> n >> m;
        ll temp;
        for (int i = 0; i < m; i++)
        {
            cin >> temp >> temp;
        }
        ll step = (m - n + 1) % k;
        if (s[step] == '2')
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
}
