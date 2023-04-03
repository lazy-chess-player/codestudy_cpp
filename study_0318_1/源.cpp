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
    {   // �ӵڶ����ַ���ʼ����Next����
        if (j == -1 || pattern[i] == pattern[j])
        {  // ��ǰ�ַ�ƥ��ɹ�
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
    getNext(pattern, next);  // ����ģʽ����Next����
    int i = 0, j = 0;
    while (i < n && j < m) 
    {
        if (j == -1 || text[i] == pattern[j]) 
        {  // ��ǰ�ַ�ƥ��ɹ�
            i++;
            j++;
        }
        else 
        {
            j = next[j];  // ʧ��ʱ����Next�������
        }
    }
    if (j == m) 
    {  // ƥ��ɹ�
        return i - j;
    }
    else 
    {  // ƥ��ʧ��
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
