// Teacher.cpp

#include "Teacher.h"

// ���캯��
Teacher::Teacher(const std::string& username) : username(username) {}

// �����û���
std::string Teacher::getUsername() const 
{
    return username;
}
