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
        cout << "请输入学生姓名：";
        cin >> name;
        cout << "请输入学生学号：";
        cin >> id;
        cout << "请输入学生语文成绩：";
        cin >> chinese;
        cout << "请输入学生数学成绩：";
        cin >> math;
        cout << "请输入学生英语成绩：";
        cin >> english;
    }

    void output()
    {
        cout << "姓名：" << name << endl;
        cout << "学号：" << id << endl;
        cout << "语文成绩：" << chinese << endl;
        cout << "数学成绩：" << math << endl;
        cout << "英语成绩：" << english << endl;
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

    cout << "请输入第一个学生的信息：" << endl;
    stu1.input();
    cout << endl;

    cout << "请输入第二个学生的信息：" << endl;
    stu2.input();
    cout << endl;

    if (stu1 == stu2)
    {
        cout << "两个学生的成绩相等" << endl;
    }
    else
    {
        if (stu1 > stu2)
        {
            cout << "第一个学生的总分高于第二个学生" << endl;
        }
        else
        {
            cout << "第二个学生的总分高于第一个学生" << endl;
        }
    }

    return 0;
}