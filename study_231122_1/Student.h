// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    // 默认构造函数
    Student() = default;

    Student(const std::string& username);

    std::string getUsername() const;
    // 其他成员函数和属性声明

private:
    std::string username;
    // 其他私有成员
};

#endif // STUDENT_H
