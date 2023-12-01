// Teacher.h

#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher 
{
public:
    // 构造函数
    Teacher(const std::string& username);

    // 获取用户名
    std::string getUsername() const;

private:

    // 用户名
    std::string username;
};

#endif // TEACHER_H
