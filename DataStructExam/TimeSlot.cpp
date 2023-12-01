// TimeSlot.cpp

#include "TimeSlot.h"

// ʱ�����ѧ�����
void TimeSlot::enqueueStudent(const Student& student)
{
    // ��鵱ǰʱ����Ƿ�����Ա
    if (students.size() < 5)
    {
        students.push(student);
        std::cout << "ԤԼ�ɹ���" << std::endl;
    }
    else
    {
        std::cerr << "���󣺸�ʱ�������Ա���޷�ԤԼ��" << std::endl;
    }
}


// ʱ�����ѧ������
void TimeSlot::dequeueStudents(int count) 
{
    while (count > 0 && !students.empty()) 
    {
        students.pop();
        count--;
    }
}

// ��ѯʱ�����
void TimeSlot::query() const 
{
    std::cout << "��ǰʱ���ѧ��������" << std::endl;
    MQueue<Student> temp = students;

    while (!temp.empty()) 
    {
        std::cout << temp.front().getUsername() << std::endl;
        temp.pop();
    }
}

// �޸�ѧ����ʱ����е����
void TimeSlot::modifyStudent(const Student& student)
{
    MQueue<Student> temp;

    while (!students.empty())
    {
        if (students.front().getUsername() == student.getUsername())
        {
            temp.push(student);
        }
        else 
        {
            temp.push(students.front());
        }

        students.pop();
    }

    students = temp;
    std::cout << "ѧ����Ϣ�޸ĳɹ���" << std::endl;
}

// ���ʱ�����ѧ������
void TimeSlot::output() const 
{
    std::cout << "��ǰʱ���ѧ��������" << std::endl;
    MQueue<Student> temp = students;

    while (!temp.empty())
    {
        std::cout << temp.front().getUsername() << std::endl;
        temp.pop();
    }
}

// ���ָ���û�����ѧ���Ƿ��Ѿ����
bool TimeSlot::isStudentEnqueued(const std::string& studentUsername) const 
{
    MQueue<Student> temp = students;

    while (!temp.empty()) 
    {
        if (temp.front().getUsername() == studentUsername) 
        {
            return true;
        }
        temp.pop();
    }

    return false;
}

// ��ָ���û�����ѧ������
void TimeSlot::dequeueStudent(const std::string& studentUsername)
{
    MQueue<Student> temp;

    while (!students.empty()) 
    {
        if (students.front().getUsername() != studentUsername) 
        {
            temp.push(students.front());
        }
        students.pop();
    }

    students = temp;
}

// ��ȡ��ǰʱ��ε�ѧ������
size_t TimeSlot::getStudentCount() const 
{
    return students.size();
}
