// User.h

#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
public:

    // ���캯��
    User(const std::string& username, const std::string& password);

    // ��ȡ�û���
    std::string getUsername() const;

    // ��ȡ�û�����
    std::string getPassword() const;

private:

    // �û���
    std::string username;

    // �û�����
    std::string password;
};

#endif // USER_H
