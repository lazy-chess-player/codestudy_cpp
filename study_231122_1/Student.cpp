// Student.cpp

#include "Student.h"

Student::Student(const std::string& username)
    : username(username) {
    // �����ڹ��캯���н���һЩ��ʼ������
}

std::string Student::getUsername() const {
    return username;
}

// ������Ա������ʵ��
