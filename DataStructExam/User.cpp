// User.cpp

#include "User.h"

// ���캯��
User::User(const std::string& username, const std::string& password) : username(username), password(password) {}

// ��ȡ�û���
std::string User::getUsername() const { return username; }

// ��ȡ�û�����
std::string User::getPassword() const { return password; }
