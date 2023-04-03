#include "student.h"
void student::study()
{
	cout << "学习" << endl;
}
void student::exam()
{
	cout << "考试成绩100分" << endl;
}
void student::set_name(string name)
{
	_name = name;
}
void student::set_age(int age)
{
	if (age < 0 || age>100)
	{
		cout << "年龄格式错误" << endl;
		_age = 0;
	}
	else
		_age = age;
}
string student::get_name()
{
	return _name;
}
int student::get_age()
{
	return _age;
}

int main()
{
	student stu;
	string name1;
	cin >> name1;
	stu.set_name(name1);
	stu.set_age(18);
	cout << stu.get_name() << "的年龄是" << stu.get_age() << endl;
	cout << stu.get_name();
	stu.study();
	cout << stu.get_name();
	stu.exam();
	return 0;
}