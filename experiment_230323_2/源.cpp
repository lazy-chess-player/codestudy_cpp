#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:
    int id;
    string name;
    string sex;
    int age;

    virtual void input() 
    {
        cout << "请输入编号：";
        cin >> id;
        cout << "请输入姓名：";
        cin >> name;
        cout << "请输入性别：";
        cin >> sex;
        cout << "请输入年龄：";
        cin >> age;
    }

    virtual void display() 
    {
        cout << "编号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "年龄：" << age << endl;
    }
};

class Student : public Person 
{
public:
    string department;
    float score;

    void input() override 
    {
        Person::input();
        cout << "请输入系别：";
        cin >> department;
        cout << "请输入成绩：";
        cin >> score;
    }

    void display() override 
    {
        Person::display();
        cout << "系别：" << department << endl;
        cout << "成绩：" << score << endl;
    }
};

class Teacher : public Person 
{
public:
    string title;
    string department;

    void input() override 
    {
        Person::input();
        cout << "请输入职称：";
        cin >> title;
        cout << "请输入部门：";
        cin >> department;
    }

    void display() override 
    {
        Person::display();
        cout << "职称：" << title << endl;
        cout << "部门：" <<department << endl;
    }
};

int main()
{
    Student s1;
    Teacher t1;

    s1.input();
    s1.display();

    t1.input();
    t1.display();

    return 0;
}