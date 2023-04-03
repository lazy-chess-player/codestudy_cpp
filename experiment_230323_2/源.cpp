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
        cout << "�������ţ�";
        cin >> id;
        cout << "������������";
        cin >> name;
        cout << "�������Ա�";
        cin >> sex;
        cout << "���������䣺";
        cin >> age;
    }

    virtual void display() 
    {
        cout << "��ţ�" << id << endl;
        cout << "������" << name << endl;
        cout << "�Ա�" << sex << endl;
        cout << "���䣺" << age << endl;
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
        cout << "������ϵ��";
        cin >> department;
        cout << "������ɼ���";
        cin >> score;
    }

    void display() override 
    {
        Person::display();
        cout << "ϵ��" << department << endl;
        cout << "�ɼ���" << score << endl;
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
        cout << "������ְ�ƣ�";
        cin >> title;
        cout << "�����벿�ţ�";
        cin >> department;
    }

    void display() override 
    {
        Person::display();
        cout << "ְ�ƣ�" << title << endl;
        cout << "���ţ�" <<department << endl;
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