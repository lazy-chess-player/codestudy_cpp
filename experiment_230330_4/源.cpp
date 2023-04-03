#include <iostream>
using namespace std;

const int row = 1;
const int col = 4;

template <class T>
class Array
{
    T var[row][col];

public:
    Array() 
    {
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                cin >> var[i][j];
            }
        }
    }

    void find(T a)
    {
        bool found = false;
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                if (var[i][j] == a) {
                    cout << "�ҵ��� " << a << "�������±�Ϊ [" << i << "][" << j << "]" << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "û���ҵ� " << a << endl;
        }
    }

    T sum() 
    {
        T sum = 0;
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                sum += var[i][j];
            }
        }
        return sum;
    }
};

int main() 
{
    Array<int> intArr;
    Array<double> doubleArr;

    int a;
    cout << "������Ҫ���ҵ�������";
    cin >> a;
    intArr.find(a);

    double b;
    cout << "������Ҫ���ҵĸ�������";
    cin >> b;
    doubleArr.find(b);

    cout << "��������ĺ�Ϊ��" << intArr.sum() << endl;
    cout << "����������ĺ�Ϊ��" << doubleArr.sum() << endl;

    return 0;
}