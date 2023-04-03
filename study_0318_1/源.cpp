#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(string pattern, vector<int>& next) 
{
    int len = pattern.length();
    next.resize(len);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < len - 1)
    {   // 从第二个字符开始计算Next数组
        if (j == -1 || pattern[i] == pattern[j])
        {  // 当前字符匹配成功
            i++;
            j++;
            next[i] = j;
        }
        else 
        {
            j = next[j];
        }
    }
}

int kmp(string text, string pattern) 
{
    int n = text.length();
    int m = pattern.length();
    vector<int> next;
    getNext(pattern, next);  // 计算模式串的Next数组
    int i = 0, j = 0;
    while (i < n && j < m) 
    {
        if (j == -1 || text[i] == pattern[j]) 
        {  // 当前字符匹配成功
            i++;
            j++;
        }
        else 
        {
            j = next[j];  // 失配时根据Next数组回溯
        }
    }
    if (j == m) 
    {  // 匹配成功
        return i - j;
    }
    else 
    {  // 匹配失败
        return -1;
    }
}

int main()
{
    string text = "ababcabcacbab";
    string pattern = "abcac";
    int pos = kmp(text, pattern);
    if (pos == -1) 
    {
        cout << "Pattern not found!" << endl;
    }
    else 
    {
        cout << "Pattern found at position " << pos << "." << endl;
    }
    return 0;
}
