#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int num;
    string name;
    char sex;
    long phone;
public:
    // ���캯��
    Student()
    {
        num = 0;
        name = "";
        sex = ' ';
        phone = 0;
    }
    Student(int n, string nm, char s, long p) {
        num = n;
        name = nm;
        sex = s;
        phone = p;
    }
    // ��ʾѧ����Ϣ
    void displayInfo()
    {
        cout << "ѧ�ţ�" << num << endl;
        cout << "������" << name << endl;
        cout << "�Ա�" << sex << endl;
        cout << "�绰��" << phone << endl;
    }
    // ��ȡѧ����Ϣ��������
    int getNum()
    {
        return num;
    };
    string getName()
    {

        return name;
    }
    long getPhone()
    {
        return phone;
    }
};
int main() {
    Student s1(1001, "����", 'M', 13912345678);
    s1.displayInfo();
    cout << endl;
    cout << "ѧ�ţ�" << s1.getNum() << endl;
    cout << "������" << s1.getName() << endl;
    cout << "�绰��" << s1.getPhone() << endl;
    return 0;
}
