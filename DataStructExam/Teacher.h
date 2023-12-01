// Teacher.h

#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher 
{
public:
    // ���캯��
    Teacher(const std::string& username);

    // ��ȡ�û���
    std::string getUsername() const;

private:

    // �û���
    std::string username;
};

#endif // TEACHER_H
