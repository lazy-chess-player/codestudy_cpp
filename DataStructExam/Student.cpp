// Student.cpp

#include "Student.h"

// 构造函数
Student::Student(const std::string& username) : username(username) {}

// 获取用户名
std::string Student::getUsername() const 
{
    return username;
}
