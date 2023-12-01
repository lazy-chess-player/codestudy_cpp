// UserManager.h

#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "User.h"
#include <vector>

#define teacherRegistrationKey "1"  // 教师注册密钥

class UserManager
{
public:
    // 用户类型枚举
    enum UserType
    {
        STUDENT,  // 学生
        TEACHER,  // 教师
        NONE      // 无效用户
    };

    // 用户登录
    UserType login(const std::string& username, const std::string& password);

    // 用户注册
    bool registerUser(const std::string& username, const std::string& password, UserManager::UserType userType, const std::string& registrationKey = "");

private:
    std::vector<User> students;  // 学生列表
    std::vector<User> teachers;  // 教师列表
};

#endif // USER_MANAGER_H
