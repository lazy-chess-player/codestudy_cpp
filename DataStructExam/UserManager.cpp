// UserManager.cpp

#include "UserManager.h"

// 用户登录
UserManager::UserType UserManager::login(const std::string& username, const std::string& password)
{
    // 查找学生用户
    for (const User& user : students)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            return STUDENT;
        }
    }

    // 查找教师用户
    for (const User& user : teachers)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            return TEACHER;
        }
    }

    return NONE;
}

// 用户注册
bool UserManager::registerUser(const std::string& username, const std::string& password, UserManager::UserType userType, const std::string& registrationKey)
{
    // 检查用户名是否已存在
    for (const User& user : (userType == UserManager::STUDENT ? students : teachers))
    {
        if (user.getUsername() == username)
        {
            std::cerr << "错误：用户名已存在。" << std::endl;
            return false;
        }
    }

    // 如果是教师账户，检查密钥是否正确
    if (userType == UserManager::TEACHER && registrationKey != teacherRegistrationKey)
    {
        std::cerr << "错误：教师注册密钥不正确。" << std::endl;
        return false;
    }

    // 创建新用户并添加到对应用户列表
    (userType == UserManager::STUDENT ? students : teachers).push_back(User(username, password));
    return true;
}
