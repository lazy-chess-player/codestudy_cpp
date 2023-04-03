#include "salary.h"
int main()
{
    int n;
    cout << "请输入职工人数：";
    cin >> n;
    salary* s = new salary[n]; 
    int no;
    string name;
    double deal, tax;
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第" << i + 1 << "个职工的信息（工号 姓名 应发工资 税金）：";
        cin >> no >> name >> deal >> tax;
        s[i] = salary(no, name, deal, tax);
    }
    cout << "工号\t姓名\t应发工资\t税金\t实发工资" << endl;
    for (int i = 0; i < n; i++) {
        s[i].output();
    }
    delete[] s; 
    return 0;
}
