// TimeSlot.h

#ifndef TIME_SLOT_H
#define TIME_SLOT_H

#include "MQueue.h"
#include "Student.h"

class TimeSlot 
{
public:
    // Ĭ�Ϲ��캯��
    TimeSlot() = default;

    // ��ѧ�����
    void enqueueStudent(const Student& student);

    // ��ָ��������ѧ������
    void dequeueStudents(int count);

    // ��ѯ��ǰʱ��ε�ѧ������
    void query() const;

    // �޸�ָ��ѧ������Ϣ
    void modifyStudent(const Student& student);

    // �����ǰʱ��ε�ѧ������
    void output() const;

    // ���ָ���û�����ѧ���Ƿ��Ѿ����
    bool isStudentEnqueued(const std::string& studentUsername) const;

    // ��ָ���û�����ѧ������
    void dequeueStudent(const std::string& studentUsername);

    // ��ȡ��ǰʱ��ε�ѧ������
    size_t getStudentCount() const;

private:
    // ʱ���ԤԼ����
    MQueue<Student> students;
};

#endif // TIME_SLOT_H
