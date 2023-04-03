#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    string id;
    int chinese;
    int math;
    int english;

    void input()
    {
        cout << "������ѧ��������";
        cin >> name;
        cout << "������ѧ��ѧ�ţ�";
        cin >> id;
        cout << "������ѧ�����ĳɼ���";
        cin >> chinese;
        cout << "������ѧ����ѧ�ɼ���";
        cin >> math;
        cout << "������ѧ��Ӣ��ɼ���";
        cin >> english;
    }

    void output()
    {
        cout << "������" << name << endl;
        cout << "ѧ�ţ�" << id << endl;
        cout << "���ĳɼ���" << chinese << endl;
        cout << "��ѧ�ɼ���" << math << endl;
        cout << "Ӣ��ɼ���" << english << endl;
    }

    bool operator==(const Student& s)
    {
        return (chinese == s.chinese && math == s.math && english == s.english);
    }

    friend bool operator>(const Student& s1, const Student& s2)
    {
        int sum1 = s1.chinese + s1.math + s1.english;
        int sum2 = s2.chinese + s2.math + s2.english;
        return (sum1 > sum2);
    }
};

int main()
{
    Student stu1, stu2;

    cout << "�������һ��ѧ������Ϣ��" << endl;
    stu1.input();
    cout << endl;

    cout << "������ڶ���ѧ������Ϣ��" << endl;
    stu2.input();
    cout << endl;

    if (stu1 == stu2)
    {
        cout << "����ѧ���ĳɼ����" << endl;
    }
    else
    {
        if (stu1 > stu2)
        {
            cout << "��һ��ѧ�����ָܷ��ڵڶ���ѧ��" << endl;
        }
        else
        {
            cout << "�ڶ���ѧ�����ָܷ��ڵ�һ��ѧ��" << endl;
        }
    }

    return 0;
}