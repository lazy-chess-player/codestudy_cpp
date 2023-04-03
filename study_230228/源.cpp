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
    // 构造函数
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
    // 显示学生信息
    void displayInfo()
    {
        cout << "学号：" << num << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "电话：" << phone << endl;
    }
    // 获取学生信息函数声明
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
    Student s1(1001, "张三", 'M', 13912345678);
    s1.displayInfo();
    cout << endl;
    cout << "学号：" << s1.getNum() << endl;
    cout << "姓名：" << s1.getName() << endl;
    cout << "电话：" << s1.getPhone() << endl;
    return 0;
}
