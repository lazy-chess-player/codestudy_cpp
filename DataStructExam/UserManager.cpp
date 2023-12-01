// UserManager.cpp

#include "UserManager.h"

// �û���¼
UserManager::UserType UserManager::login(const std::string& username, const std::string& password)
{
    // ����ѧ���û�
    for (const User& user : students)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            return STUDENT;
        }
    }

    // ���ҽ�ʦ�û�
    for (const User& user : teachers)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            return TEACHER;
        }
    }

    return NONE;
}

// �û�ע��
bool UserManager::registerUser(const std::string& username, const std::string& password, UserManager::UserType userType, const std::string& registrationKey)
{
    // ����û����Ƿ��Ѵ���
    for (const User& user : (userType == UserManager::STUDENT ? students : teachers))
    {
        if (user.getUsername() == username)
        {
            std::cerr << "�����û����Ѵ��ڡ�" << std::endl;
            return false;
        }
    }

    // ����ǽ�ʦ�˻��������Կ�Ƿ���ȷ
    if (userType == UserManager::TEACHER && registrationKey != teacherRegistrationKey)
    {
        std::cerr << "���󣺽�ʦע����Կ����ȷ��" << std::endl;
        return false;
    }

    // �������û�����ӵ���Ӧ�û��б�
    (userType == UserManager::STUDENT ? students : teachers).push_back(User(username, password));
    return true;
}
