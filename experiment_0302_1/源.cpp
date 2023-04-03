#include <iostream>
using namespace std;

int compare(const void* a, const void* b)
{
    const int* p = (const int*)a;
    const int* q = (const int*)b;
    return *p - *q;
}
int main()
{
    int n;
    cout << "---- 输入整数个数 ----" << endl;
    cin >> n;

    //动态申请空间
    int* arr = new int[n];
    cout << "---- 输入整数序列 ----" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //排序
    qsort(arr, n, sizeof(int), compare);

    cout << "---- 排序结果如下 ----" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
