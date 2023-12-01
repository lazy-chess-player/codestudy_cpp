#include <iostream>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2

using namespace std;

typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
    SElemType data;
    struct StackNode* next;
} StackNode, * LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

Status InitStack(LinkStack& S)
{
    S.top = nullptr;
    S.count = 0;
    return OK;
}

Status Push(LinkStack& S, SElemType e)
{
    LinkStackPtr s = new StackNode;
    s->data = e;
    s->next = S.top;
    S.top = s;
    S.count++;
    return OK;
}

Status Pop(LinkStack& S, SElemType& e)
{
    if (S.top == nullptr)
        return ERROR;
    LinkStackPtr p = S.top;
    e = p->data;
    S.top = p->next;
    delete p;
    S.count--;
    return OK;
}

Status GetTop(LinkStack& S, SElemType& e)
{
    if (S.top == nullptr)
        return ERROR;
    e = S.top->data;
    return OK;
}

Status IsEmpty(LinkStack& S)
{
    return S.count == 0 ? TRUE : FALSE;
}

void PrintStack(LinkStack& S)
{
    LinkStackPtr p = S.top;
    cout << "Stack: ";
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkStack S;
    int choice, n;
    SElemType temp;
    Status result;
    InitStack(S);
    while (true)
    {
        cout << "��ѡ�������\n";
        cout << "1. ����Ԫ��" << endl;
        cout << "2. ��ջ" << endl;
        cout << "3. ȡջ��" << endl;
        cout << "4. ջ�Ƿ�Ϊ��" << endl;
        cout << "5. ��ӡջ" << endl;
        cout << "0. �˳�" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "������Ҫ�����Ԫ�ظ�����";
            cin >> n;
            cout << "������Ҫ�����Ԫ�أ�";
            while (n--)
            {
                cin >> temp;
                result = Push(S, temp);
                if (result != OK)
                {
                    cout << "����Ԫ��ʧ�ܣ�" << endl;
                    break;
                }
            }
            break;
        case 2:
            cout << "������Ҫ������Ԫ�ظ�����";
            cin >> n;
            while (n--)
            {
                result = Pop(S, temp);
                if (result != OK)
                {
                    cout << "����Ԫ��ʧ�ܣ�";
                    break;
                }
                else
                    cout << temp << ' ';
            }
            cout << endl;
            break;
        case 3:
            result = GetTop(S, temp);
            if (result != OK)
            {
                cout << "��ȡջ��Ԫ��ʧ�ܣ�" << endl;
                break;
            }
            else
                cout << "ջ��Ԫ��Ϊ��" << temp << endl;
            break;
        case 4:
            if (IsEmpty(S))
                cout << "ջΪ�գ�" << endl;
            else
                cout << "ջ��Ϊ�գ�" << endl;
            break;
        case 5:
            PrintStack(S);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "��Ч���룡" << endl;
            break;
        }
    }
    return 0;
}
