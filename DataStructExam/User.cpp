// User.cpp

#include "User.h"

// 构造函数
User::User(const std::string& username, const std::string& password) : username(username), password(password) {}

// 获取用户名
std::string User::getUsername() const { return username; }

// 获取用户密码
std::string User::getPassword() const { return password; }
