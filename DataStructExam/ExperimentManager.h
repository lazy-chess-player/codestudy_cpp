// ExperimentManager.h

#ifndef EXPERIMENT_MANAGER_H
#define EXPERIMENT_MANAGER_H

#include <vector>
#include "TimeSlot.h"
#include "Student.h"

class ExperimentManager
{
public:
    // 默认构造函数声明
    ExperimentManager();

    // 在特定时间段插入学生
    void insertStudent(const Student& student, int timeSlotIndex);

    // 在特定时间段删除学生
    void deleteStudents(int timeSlotIndex);

    // 查询特定时间段的学生名单
    void query(int timeSlotIndex) const;

    // 修改特定时间段的学生信息
    void modifyStudent(int timeSlotIndex, const Student& student);

    // 输出特定时间段的学生名单
    void output(int timeSlotIndex) const;

    // 预约实验室
    bool reserveLab(const std::string& studentUsername, int timeSlotIndex);

    // 取消预约
    bool cancelReservation(const std::string& studentUsername, int timeSlotIndex);

    // 显示学生的所有预约情况
    void displayStudentReservations(const std::string& studentUsername) const;

    // 获取特定时间段的名称
    std::string getTimeSlotName(int timeSlotIndex) const;

    // 检查是否可以预约实验室
    bool canReserveLab(int timeSlotIndex) const;

    // 获取时间段数量
    size_t getTimeSlotCount() const;

private:

    // 时间段数组
    std::vector<TimeSlot> timeSlots;
};

#endif // EXPERIMENT_MANAGER_H
