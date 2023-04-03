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
                    cout << "找到了 " << a << "，它的下标为 [" << i << "][" << j << "]" << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "没有找到 " << a << endl;
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
    cout << "请输入要查找的整数：";
    cin >> a;
    intArr.find(a);

    double b;
    cout << "请输入要查找的浮点数：";
    cin >> b;
    doubleArr.find(b);

    cout << "整数数组的和为：" << intArr.sum() << endl;
    cout << "浮点数数组的和为：" << doubleArr.sum() << endl;

    return 0;
}