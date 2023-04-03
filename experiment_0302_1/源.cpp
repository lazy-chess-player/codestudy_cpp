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
    cout << "---- ������������ ----" << endl;
    cin >> n;

    //��̬����ռ�
    int* arr = new int[n];
    cout << "---- ������������ ----" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //����
    qsort(arr, n, sizeof(int), compare);

    cout << "---- ���������� ----" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
