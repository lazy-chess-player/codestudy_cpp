// UserManager.h

#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "User.h"
#include <vector>

#define teacherRegistrationKey "1"  // ��ʦע����Կ

class UserManager
{
public:
    // �û�����ö��
    enum UserType
    {
        STUDENT,  // ѧ��
        TEACHER,  // ��ʦ
        NONE      // ��Ч�û�
    };

    // �û���¼
    UserType login(const std::string& username, const std::string& password);

    // �û�ע��
    bool registerUser(const std::string& username, const std::string& password, UserManager::UserType userType, const std::string& registrationKey = "");

private:
    std::vector<User> students;  // ѧ���б�
    std::vector<User> teachers;  // ��ʦ�б�
};

#endif // USER_MANAGER_H
