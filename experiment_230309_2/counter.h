#pragma once
#include<iostream>
class counter
{
public:
	counter(int number);
	void increment();     	//��ԭֵ��1
	void decrement();     	//��ԭֵ��1
	int getvalue();       	//ȡ�ü�����ֵ
	void print();         	//��ʾ������ֵ
private:
	int value;
};

