#include "salary.h"
int main()
{
    int n;
    cout << "������ְ��������";
    cin >> n;
    salary* s = new salary[n]; 
    int no;
    string name;
    double deal, tax;
    for (int i = 0; i < n; i++)
    {
        cout << "�������" << i + 1 << "��ְ������Ϣ������ ���� Ӧ������ ˰�𣩣�";
        cin >> no >> name >> deal >> tax;
        s[i] = salary(no, name, deal, tax);
    }
    cout << "����\t����\tӦ������\t˰��\tʵ������" << endl;
    for (int i = 0; i < n; i++) {
        s[i].output();
    }
    delete[] s; 
    return 0;
}
