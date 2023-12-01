// TimeSlot.h

#ifndef TIME_SLOT_H
#define TIME_SLOT_H

#include "MQueue.h"
#include "Student.h"

class TimeSlot 
{
public:
    // 默认构造函数
    TimeSlot() = default;

    // 将学生入队
    void enqueueStudent(const Student& student);

    // 将指定数量的学生出队
    void dequeueStudents(int count);

    // 查询当前时间段的学生名单
    void query() const;

    // 修改指定学生的信息
    void modifyStudent(const Student& student);

    // 输出当前时间段的学生名单
    void output() const;

    // 检查指定用户名的学生是否已经入队
    bool isStudentEnqueued(const std::string& studentUsername) const;

    // 将指定用户名的学生出队
    void dequeueStudent(const std::string& studentUsername);

    // 获取当前时间段的学生数量
    size_t getStudentCount() const;

private:
    // 时间段预约队列
    MQueue<Student> students;
};

#endif // TIME_SLOT_H
