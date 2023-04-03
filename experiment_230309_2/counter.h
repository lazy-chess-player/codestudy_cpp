#pragma once
#include<iostream>
class counter
{
public:
	counter(int number);
	void increment();     	//给原值加1
	void decrement();     	//给原值减1
	int getvalue();       	//取得计数器值
	void print();         	//显示计数器值
private:
	int value;
};

