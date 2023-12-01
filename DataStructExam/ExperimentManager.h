// ExperimentManager.h

#ifndef EXPERIMENT_MANAGER_H
#define EXPERIMENT_MANAGER_H

#include <vector>
#include "TimeSlot.h"
#include "Student.h"

class ExperimentManager
{
public:
    // Ĭ�Ϲ��캯������
    ExperimentManager();

    // ���ض�ʱ��β���ѧ��
    void insertStudent(const Student& student, int timeSlotIndex);

    // ���ض�ʱ���ɾ��ѧ��
    void deleteStudents(int timeSlotIndex);

    // ��ѯ�ض�ʱ��ε�ѧ������
    void query(int timeSlotIndex) const;

    // �޸��ض�ʱ��ε�ѧ����Ϣ
    void modifyStudent(int timeSlotIndex, const Student& student);

    // ����ض�ʱ��ε�ѧ������
    void output(int timeSlotIndex) const;

    // ԤԼʵ����
    bool reserveLab(const std::string& studentUsername, int timeSlotIndex);

    // ȡ��ԤԼ
    bool cancelReservation(const std::string& studentUsername, int timeSlotIndex);

    // ��ʾѧ��������ԤԼ���
    void displayStudentReservations(const std::string& studentUsername) const;

    // ��ȡ�ض�ʱ��ε�����
    std::string getTimeSlotName(int timeSlotIndex) const;

    // ����Ƿ����ԤԼʵ����
    bool canReserveLab(int timeSlotIndex) const;

    // ��ȡʱ�������
    size_t getTimeSlotCount() const;

private:

    // ʱ�������
    std::vector<TimeSlot> timeSlots;
};

#endif // EXPERIMENT_MANAGER_H
