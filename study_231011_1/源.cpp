#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//队列
//bool checkInWordMap(queue<int> map,int word)
//{
//	while (!map.empty())
//	{
//		if (word == map.front())
//			return true;
//		map.pop();
//	}
//	return false;
//}
//
//void solve()
//{
//	int m, n;
//	cin >> m >> n;
//	queue< int> wordMap;
//	int ans = 0;
//	vector<int> words(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> words[i];
//	}
//	int i = 0;
//	while (wordMap.size() < m && i < n)
//	{
//		if (checkInWordMap(wordMap, words[i]))
//		{
//			i++;
//			continue;
//		}
//		else
//		{
//			wordMap.push(words[i]);
//			ans++;
//		}
//		i++;
//	}
//	for (; i < n; i++)
//	{
//		if (checkInWordMap(wordMap, words[i]))
//			continue;
//		else
//		{
//			wordMap.pop();
//			wordMap.push(words[i]);
//			ans++;
//		}
//	}
//	cout << ans << endl;
//}

//滑动窗口
int l = 0, r = 0;

bool checkWindows(vector<int> words, int& word)
{
	for (int i = l; i < r; i++)
	{
		if (words[i] == word)
		{
			word = -1;
			return true;
		}
	}
	return false;
}

void solve()
{
	int m, n;
	cin >> m >> n;
	int ans = 0;
	vector<int> words(n);
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
	int remainingCapacity = m;
	while (r < n && remainingCapacity)
	{
		if (!checkWindows(words, words[r]))
		{
			ans++;
			remainingCapacity--;
		}
		r++;
	}
	for (; r < n; r++)
	{
		if (!checkWindows(words, words[r]))
		{
			ans++;
			l++;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}