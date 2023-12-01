// Teacher.cpp

#include "Teacher.h"

// 构造函数
Teacher::Teacher(const std::string& username) : username(username) {}

// 返回用户名
std::string Teacher::getUsername() const 
{
    return username;
}
