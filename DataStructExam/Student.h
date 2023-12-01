// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student 
{
public:
    // 默认构造函数
    Student() = default;

    // 传参构造函数
    Student(const std::string& username);

    // 获取用户名
    std::string getUsername() const;

private:

    // 用户名
    std::string username;
};

#endif // STUDENT_H
