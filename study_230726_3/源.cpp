#include <string>
#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (s.size() == 1||s.back()== 1)
		{
			cout << 1 << endl;
			continue;
		}
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                for (int j = i; j >= 0; j--)
                {
                    ans++;
                    if (s[j] == '1')
                        break;
                }
                break;
            }
        }
        if (ans > 0)
            cout << ans << endl;
        else
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                ans++;
                if (s[i] == '1')
                    break;
            }
            cout << ans << endl;
        }
	}
	return 0;
}