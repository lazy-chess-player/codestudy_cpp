#include <iostream>
using namespace std;

template <typename T>
T maxElement(T arr[], int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
double average(T arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    int intArr[] = { 1, 2, 3, 4, 5 };
    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    cout << "intArr�����Ԫ��Ϊ��" << maxElement(intArr, 5) << endl;
    cout << "intArr��ƽ��ֵΪ��" << average(intArr, 5) << endl;

    cout << "doubleArr�����Ԫ��Ϊ��" << maxElement(doubleArr, 5) << endl;
    cout << "doubleArr��ƽ��ֵΪ��" << average(doubleArr, 5) << endl;

    return 0;
}