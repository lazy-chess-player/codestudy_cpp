// User.h

#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
public:

    // 构造函数
    User(const std::string& username, const std::string& password);

    // 获取用户名
    std::string getUsername() const;

    // 获取用户密码
    std::string getPassword() const;

private:

    // 用户名
    std::string username;

    // 用户密码
    std::string password;
};

#endif // USER_H
