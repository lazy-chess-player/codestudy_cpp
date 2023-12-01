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

    std::cout << "队列大小: " << studentQueue.size() << std::endl;
    std::cout << "队列是否为空: " << (studentQueue.empty() ? "是" : "否") << std::endl;

    for (int i = 0; i < 2; ++i)
    {
        studentQueue.pop();
    }

    std::cout << "操作后队列大小: " << studentQueue.size() << std::endl;
    std::cout << "操作后队列是否为空: " << (studentQueue.empty() ? "是" : "否") << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        studentQueue.pop();
    }

    std::cout << "操作后队列大小: " << studentQueue.size() << std::endl;
    std::cout << "操作后队列是否为空: " << (studentQueue.empty() ? "是" : "否") << std::endl;

    return 0;
}
