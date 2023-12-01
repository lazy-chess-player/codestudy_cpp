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
        cout << "请选择操作：\n";
        cout << "1. 插入元素" << endl;
        cout << "2. 弹栈" << endl;
        cout << "3. 取栈顶" << endl;
        cout << "4. 栈是否为空" << endl;
        cout << "5. 打印栈" << endl;
        cout << "0. 退出" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "请输入要插入的元素个数：";
            cin >> n;
            cout << "请输入要插入的元素：";
            while (n--)
            {
                cin >> temp;
                result = Push(S, temp);
                if (result != OK)
                {
                    cout << "插入元素失败！" << endl;
                    break;
                }
            }
            break;
        case 2:
            cout << "请输入要弹出的元素个数：";
            cin >> n;
            while (n--)
            {
                result = Pop(S, temp);
                if (result != OK)
                {
                    cout << "弹出元素失败！";
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
                cout << "获取栈顶元素失败！" << endl;
                break;
            }
            else
                cout << "栈顶元素为：" << temp << endl;
            break;
        case 4:
            if (IsEmpty(S))
                cout << "栈为空！" << endl;
            else
                cout << "栈不为空！" << endl;
            break;
        case 5:
            PrintStack(S);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "无效输入！" << endl;
            break;
        }
    }
    return 0;
}
