// Student.cpp

#include "Student.h"

// ���캯��
Student::Student(const std::string& username) : username(username) {}

// ��ȡ�û���
std::string Student::getUsername() const 
{
    return username;
}
