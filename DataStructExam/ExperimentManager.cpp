// ExperimentManager.cpp

#include "ExperimentManager.h"
#include <iostream>

// �� ExperimentManager ���캯���г�ʼ��ʱ���
ExperimentManager::ExperimentManager()
{
    // �̶�������ʱ���
    timeSlots.push_back(TimeSlot());
    timeSlots.push_back(TimeSlot());
    timeSlots.push_back(TimeSlot());
}

// ��ָ��ʱ��β���ѧ��
void ExperimentManager::insertStudent(const Student& student, int timeSlotIndex)
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].enqueueStudent(student);
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
    }
}

// ���ָ��ʱ��ε�����ԤԼ
void ExperimentManager::deleteStudents(int timeSlotIndex)
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // ��ո�ʱ��ε�����ԤԼ
        timeSlots[timeSlotIndex].dequeueStudents(5);
        std::cout << "��ʱ���ԤԼ��ճɹ���" << std::endl;
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
    }
}

// ��ѯָ��ʱ��ε�ѧ������
void ExperimentManager::query(int timeSlotIndex) const
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].query();
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
    }
}

// �޸�ָ��ʱ��ε�ѧ����Ϣ
void ExperimentManager::modifyStudent(int timeSlotIndex, const Student& student)
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].modifyStudent(student);
        std::cout << "ѧ����Ϣ�޸ĳɹ���" << std::endl;
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
    }
}

// ���ָ��ʱ��ε�ѧ������
void ExperimentManager::output(int timeSlotIndex) const
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].output();
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
    }
}

// ԤԼʵ���ң������Ƿ�ԤԼ�ɹ�
bool ExperimentManager::reserveLab(const std::string& studentUsername, int timeSlotIndex)
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // ���ѧ���Ƿ��Ѿ�ԤԼ����ʱ���
        if (timeSlots[timeSlotIndex].isStudentEnqueued(studentUsername))
        {
            std::cerr << "�������Ѿ�ԤԼ����ʱ��Ρ�" << std::endl;
            return false;
        }

        // ��ѧ�����뵽ʱ��εĶ�����
        timeSlots[timeSlotIndex].enqueueStudent(Student(studentUsername));
        return true;
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
        return false;
    }
}

// ȡ��ԤԼ�������Ƿ�ȡ���ɹ�
bool ExperimentManager::cancelReservation(const std::string& studentUsername, int timeSlotIndex)
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // ���ѧ���Ƿ�ԤԼ�˸�ʱ���
        if (timeSlots[timeSlotIndex].isStudentEnqueued(studentUsername))
        {
            // ��ѧ����ʱ��εĶ������Ƴ�
            timeSlots[timeSlotIndex].dequeueStudent(studentUsername);
            std::cout << "ȡ��ԤԼ�ɹ���" << std::endl;
            return true;
        }
        else
        {
            std::cerr << "�����㲢û��ԤԼ��ʱ��Ρ�" << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
        return false;
    }
}

// ��ʾѧ��������ԤԼ���
void ExperimentManager::displayStudentReservations(const std::string& studentUsername) const
{
    std::cout << "���ԤԼ�����" << std::endl;

    for (size_t i = 0; i < timeSlots.size(); ++i)
    {
        if (timeSlots[i].isStudentEnqueued(studentUsername))
        {
            std::cout << "ʱ��� " << i + 1 << " " << getTimeSlotName(i) << ": ��ԤԼ" << std::endl;
        }
        else
        {
            std::cout << "ʱ��� " << i + 1 << " " << getTimeSlotName(i) << ": δԤԼ" << std::endl;
        }
    }
}

// ��ȡʱ�������
size_t ExperimentManager::getTimeSlotCount() const
{
    return timeSlots.size();
}

// ��ȡָ��ʱ��ε�����
std::string ExperimentManager::getTimeSlotName(int timeSlotIndex) const
{
    // �̶���ʱ�������
    static const std::vector<std::string> timeSlotNames = { "��һ����", "��������", "��������" };

    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlotNames.size())
    {
        return timeSlotNames[timeSlotIndex];
    }
    else
    {
        return "δ֪ʱ���";
    }
}

// ���ָ��ʱ����Ƿ���ԤԼ
bool ExperimentManager::canReserveLab(int timeSlotIndex) const
{
    // ���ʱ����Ƿ�Ϸ�
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // ���ʱ����Ƿ���ԤԼ
        return timeSlots[timeSlotIndex].getStudentCount() < 5;
    }
    else
    {
        return false;
    }
}
