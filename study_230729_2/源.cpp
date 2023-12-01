//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef long long ll;
//
//int main()
//{
//    int t;
//    cin >> t;
//
//    while (t--)
//    {
//        ll n;
//        cin >> n;
//
//        int mx = 1;
//        for (ll i = 1; i * i <= n; i++)
//        {
//            if (n % i == 0)
//            {
//                ll j = i;
//                while (j * j <= n && n % j == 0)
//                {
//                    j++;
//                }
//                mx = mx > j - i ? mx : j - i;
//                i += 1000000000000000;
//            }
//        }
//        cout<<mx<<endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> solveTestCase(vector<int>& a) {
    vector<pair<int, int>> operations;
    int n = a.size();

    for (int i = 1; i < n; i++) {
        while (a[i] < a[i - 1]) {
            a[i] += a[i - 1];
            operations.push_back({ i, i - 1 });
        }
    }

    return operations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> operations = solveTestCase(a);

        cout << operations.size() << endl;
        for (const auto& op : operations) {
            cout << op.first + 1 << " " << op.second + 1 << endl;
        }
    }

    return 0;
}
