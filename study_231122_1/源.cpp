#include <iostream>
#include "MQueue.h"
#include "Student.h"

int main() 
{
    MQueue<Student, 5> studentQueue;

    for (int i = 1; i <= 5; ++i)
    {
        studentQueue.push(Student(std::to_string(i)));
    }

    std::cout << "���д�С: " << studentQueue.size() << std::endl;
    std::cout << "�����Ƿ�Ϊ��: " << (studentQueue.empty() ? "��" : "��") << std::endl;

    for (int i = 0; i < 2; ++i)
    {
        studentQueue.pop();
    }

    std::cout << "��������д�С: " << studentQueue.size() << std::endl;
    std::cout << "����������Ƿ�Ϊ��: " << (studentQueue.empty() ? "��" : "��") << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        studentQueue.pop();
    }

    std::cout << "��������д�С: " << studentQueue.size() << std::endl;
    std::cout << "����������Ƿ�Ϊ��: " << (studentQueue.empty() ? "��" : "��") << std::endl;

    return 0;
}
