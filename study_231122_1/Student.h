// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    // Ĭ�Ϲ��캯��
    Student() = default;

    Student(const std::string& username);

    std::string getUsername() const;
    // ������Ա��������������

private:
    std::string username;
    // ����˽�г�Ա
};

#endif // STUDENT_H
