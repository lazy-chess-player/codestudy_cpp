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
    string name; //姓名  
    char sex; //性别，'M'表示男性， 'F'表示女性  
} Dancer;

#define MAX_SIZE 100  

typedef struct {
    Dancer dancers[MAX_SIZE]; //跳舞者数组  
    int front; //队头指针  
    int rear; //队尾指针  
} SqQueue;


Status InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue(SqQueue& Q, Dancer e) {
    if ((Q.rear + 1) % MAX_SIZE == Q.front) {
        return ERROR; //队列已满  
    }
    Q.dancers[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return OK;
}

Status DeQueue(SqQueue& Q, Dancer& e) {
    if (Q.front == Q.rear) {
        return ERROR; //队列已空  
    }
    e = Q.dancers[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return OK;
}

Status GetHead(SqQueue Q, Dancer& e) {
    if (Q.front == Q.rear) {
        return ERROR; //队列已空  
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
    cout << "请输入舞者人数:";
    cin >> n;
    vector<Dancer> dancers(n);
    cout << "请输入舞者姓名和性别：\n";
    for (int i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "位:\n";
        cout << "姓名："; cin >> dancers[i].name;
        cout << "性别："; cin >> dancers[i].sex;
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
    cout << "已经配对的舞伴:\n";
    int i = 1;
    while (!IsQueueEmpty(men) && !IsQueueEmpty(women))
    {
        Dancer man, woman;
        DeQueue(men, man);
        DeQueue(women, woman);
        cout << "第" << i++ << "对：" << man.name << "和" << woman.name << endl;
    }
    if (!IsQueueEmpty(men))
    {
        Dancer man;
        GetHead(men, man);
        cout << "下一轮舞曲开始时，第一个可获得舞伴的人是：" << man.name << endl;
    }
    else if (!IsQueueEmpty(women))
    {
        Dancer woman;
        GetHead(women, woman);
        cout << "下一轮舞曲开始时，第一个可获得舞伴的人是：" << woman.name;
    }
    return 0;
}
