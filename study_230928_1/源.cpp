#include<iostream>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 1
#define OVERFLOW -2
#define STACK_INIT_SIZE 80   
#define STACKINCREMENT  10  
typedef int SElemType;
typedef int Status;

using namespace std;

typedef struct {
	SElemType* base;
	SElemType* top;
	int  stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
SElemType GetTop(SqStack& S,SElemType& e);
//void Display(SqStack* S);

int main()
{
	SqStack S;
	SElemType e;
	int choose = -1;
	while (choose != 0)
	{
		cout << "��ѡ��" << endl;
		cout << "1.����" << endl;
		cout << "2.��ջ" << endl;
		cout << "3.��ջ" << endl;
		cout << "4.ȡջ��" << endl;
		cin >> choose;

		switch (choose)
		{
		case 1:
			InitStack(S);
			cout << "�����ɹ�" << endl;
			break;
		case 2:
			cout << "������e��" << endl;
			cin >> e;
			Push(S, e);
			cout << "��ջ�ɹ�" << endl;
			//Display(S);
			break;
		case 3:
			Pop(S, e);
			cout << e << endl;
			cout << "��ջ�ɹ�" << endl;
			break;
		case 4:
			int topNum = 0;
			int condition = GetTop(S,topNum);
			if (condition == ERROR)
				cout << "��ȡջ��Ԫ��ʧ��" << endl;
			else
				cout << topNum << endl;
			break;
		}
		system("pause");
	}

}

Status InitStack(SqStack& S)
{
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base) return(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) return ERROR;
	*S.top = e;
	S.top += 1;
}

Status Pop(SqStack& S, SElemType& e)
{
	if (S.base == S.top) 
		return ERROR;
	e = *S.top;
	S.top -= 1;
}

Status GetTop(SqStack& S,SElemType& e)
{
	if (S.top != S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}
/*
void Display(SqStack &S)
{
	SElemType *p;
	int i = 1;
	while(p != S.top)
	{
		cout<<i<<":"<<*p<<endl;
		p++;
		i++;
	}
}
*/