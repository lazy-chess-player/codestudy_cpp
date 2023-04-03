#pragma once
#include<iostream>
#include<string>
using namespace std;
class salary
{
protected:
	int _no;
	string _name;
	double _deal;
	double _tax;
	double _fact;
public:
	double CountFact(double, double);
	salary();
	salary(int, string, double, double);
    void output();
};
salary::salary():
	_no(0),_name("Пе"),_deal(0.0),_tax(0.0)
{
}
salary::salary(int no, string name, double deal,double tax)
{
	_no = no;
	_name = name;
	_deal = deal;
	_tax = tax;
	_fact = CountFact(_deal, _tax);
}

double salary::CountFact(double deal, double tax)
{
	return deal - tax;
}
void salary:: output()
{
    cout << _no << "\t" << _name << "\t" << _deal << "\t" << _tax << "\t" << _fact << endl;
}
