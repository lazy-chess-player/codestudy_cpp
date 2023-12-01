// Student.cpp

#include "Student.h"

Student::Student(const std::string& username)
    : username(username) {
    // 可以在构造函数中进行一些初始化工作
}

std::string Student::getUsername() const {
    return username;
}

// 其他成员函数的实现
