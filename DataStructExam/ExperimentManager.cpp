// ExperimentManager.cpp

#include "ExperimentManager.h"
#include <iostream>

// 在 ExperimentManager 构造函数中初始化时间段
ExperimentManager::ExperimentManager()
{
    // 固定的三个时间段
    timeSlots.push_back(TimeSlot());
    timeSlots.push_back(TimeSlot());
    timeSlots.push_back(TimeSlot());
}

// 向指定时间段插入学生
void ExperimentManager::insertStudent(const Student& student, int timeSlotIndex)
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].enqueueStudent(student);
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
    }
}

// 清空指定时间段的所有预约
void ExperimentManager::deleteStudents(int timeSlotIndex)
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // 清空该时间段的所有预约
        timeSlots[timeSlotIndex].dequeueStudents(5);
        std::cout << "该时间段预约清空成功。" << std::endl;
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
    }
}

// 查询指定时间段的学生名单
void ExperimentManager::query(int timeSlotIndex) const
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].query();
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
    }
}

// 修改指定时间段的学生信息
void ExperimentManager::modifyStudent(int timeSlotIndex, const Student& student)
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].modifyStudent(student);
        std::cout << "学生信息修改成功。" << std::endl;
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
    }
}

// 输出指定时间段的学生名单
void ExperimentManager::output(int timeSlotIndex) const
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        timeSlots[timeSlotIndex].output();
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
    }
}

// 预约实验室，返回是否预约成功
bool ExperimentManager::reserveLab(const std::string& studentUsername, int timeSlotIndex)
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // 检查学生是否已经预约过该时间段
        if (timeSlots[timeSlotIndex].isStudentEnqueued(studentUsername))
        {
            std::cerr << "错误：你已经预约过该时间段。" << std::endl;
            return false;
        }

        // 将学生插入到时间段的队列中
        timeSlots[timeSlotIndex].enqueueStudent(Student(studentUsername));
        return true;
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
        return false;
    }
}

// 取消预约，返回是否取消成功
bool ExperimentManager::cancelReservation(const std::string& studentUsername, int timeSlotIndex)
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // 检查学生是否预约了该时间段
        if (timeSlots[timeSlotIndex].isStudentEnqueued(studentUsername))
        {
            // 将学生从时间段的队列中移除
            timeSlots[timeSlotIndex].dequeueStudent(studentUsername);
            std::cout << "取消预约成功。" << std::endl;
            return true;
        }
        else
        {
            std::cerr << "错误：你并没有预约该时间段。" << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << "错误：无效的时间段。" << std::endl;
        return false;
    }
}

// 显示学生的所有预约情况
void ExperimentManager::displayStudentReservations(const std::string& studentUsername) const
{
    std::cout << "你的预约情况：" << std::endl;

    for (size_t i = 0; i < timeSlots.size(); ++i)
    {
        if (timeSlots[i].isStudentEnqueued(studentUsername))
        {
            std::cout << "时间段 " << i + 1 << " " << getTimeSlotName(i) << ": 已预约" << std::endl;
        }
        else
        {
            std::cout << "时间段 " << i + 1 << " " << getTimeSlotName(i) << ": 未预约" << std::endl;
        }
    }
}

// 获取时间段总数
size_t ExperimentManager::getTimeSlotCount() const
{
    return timeSlots.size();
}

// 获取指定时间段的名称
std::string ExperimentManager::getTimeSlotName(int timeSlotIndex) const
{
    // 固定的时间段名称
    static const std::vector<std::string> timeSlotNames = { "周一下午", "周三下午", "周五下午" };

    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlotNames.size())
    {
        return timeSlotNames[timeSlotIndex];
    }
    else
    {
        return "未知时间段";
    }
}

// 检查指定时间段是否还能预约
bool ExperimentManager::canReserveLab(int timeSlotIndex) const
{
    // 检查时间段是否合法
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        // 检查时间段是否还能预约
        return timeSlots[timeSlotIndex].getStudentCount() < 5;
    }
    else
    {
        return false;
    }
}
