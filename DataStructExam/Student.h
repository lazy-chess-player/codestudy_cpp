// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student 
{
public:
    // Ĭ�Ϲ��캯��
    Student() = default;

    // ���ι��캯��
    Student(const std::string& username);

    // ��ȡ�û���
    std::string getUsername() const;

private:

    // �û���
    std::string username;
};

#endif // STUDENT_H
