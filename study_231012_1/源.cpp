#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Status
{
    ERROR = 0,
    OK = 1
};

typedef struct
{
    string name; //����  
    char sex; //�Ա�'M'��ʾ���ԣ� 'F'��ʾŮ��  
} Dancer;

#define MAX_SIZE 100  

typedef struct {
    Dancer dancers[MAX_SIZE]; //����������  
    int front; //��ͷָ��  
    int rear; //��βָ��  
} SqQueue;


Status InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue(SqQueue& Q, Dancer e) {
    if ((Q.rear + 1) % MAX_SIZE == Q.front) {
        return ERROR; //��������  
    }
    Q.dancers[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return OK;
}

Status DeQueue(SqQueue& Q, Dancer& e) {
    if (Q.front == Q.rear) {
        return ERROR; //�����ѿ�  
    }
    e = Q.dancers[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return OK;
}

Status GetHead(SqQueue Q, Dancer& e) {
    if (Q.front == Q.rear) {
        return ERROR; //�����ѿ�  
    }
    e = Q.dancers[Q.front];
    return OK;
}

bool IsQueueEmpty(const SqQueue& Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

int main()
{
    SqQueue men;
    SqQueue women;
    InitQueue(men);
    InitQueue(women);
    int n;
    cout << "��������������:";
    cin >> n;
    vector<Dancer> dancers(n);
    cout << "�����������������Ա�\n";
    for (int i = 0; i < n; i++)
    {
        cout << "��" << i + 1 << "λ:\n";
        cout << "������"; cin >> dancers[i].name;
        cout << "�Ա�"; cin >> dancers[i].sex;
        Dancer d = dancers[i];
        if (d.sex == 'M')
        {
            EnQueue(men, d);
        }
        else
        {
            EnQueue(women, d);
        }
    }
    cout << "�Ѿ���Ե����:\n";
    int i = 1;
    while (!IsQueueEmpty(men) && !IsQueueEmpty(women))
    {
        Dancer man, woman;
        DeQueue(men, man);
        DeQueue(women, woman);
        cout << "��" << i++ << "�ԣ�" << man.name << "��" << woman.name << endl;
    }
    if (!IsQueueEmpty(men))
    {
        Dancer man;
        GetHead(men, man);
        cout << "��һ��������ʼʱ����һ���ɻ���������ǣ�" << man.name << endl;
    }
    else if (!IsQueueEmpty(women))
    {
        Dancer woman;
        GetHead(women, woman);
        cout << "��һ��������ʼʱ����һ���ɻ���������ǣ�" << woman.name;
    }
    return 0;
}
