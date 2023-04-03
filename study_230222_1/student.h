#include<iostream>
using namespace std;
class student
{
public:
	void study();
	void exam();
	void set_name(string name);
	void set_age(int age);
	string get_name();
	int get_age();
private:
	string _name;
	int _age;
};