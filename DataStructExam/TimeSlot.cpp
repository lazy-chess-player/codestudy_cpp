// TimeSlot.cpp

#include "TimeSlot.h"

// 时间队列学生入队
void TimeSlot::enqueueStudent(const Student& student)
{
    // 检查当前时间段是否已满员
    if (students.size() < 5)
    {
        students.push(student);
        std::cout << "预约成功。" << std::endl;
    }
    else
    {
        std::cerr << "错误：该时间段已满员，无法预约。" << std::endl;
    }
}


// 时间队列学生出队
void TimeSlot::dequeueStudents(int count) 
{
    while (count > 0 && !students.empty()) 
    {
        students.pop();
        count--;
    }
}

// 查询时间队列
void TimeSlot::query() const 
{
    std::cout << "当前时间段学生名单：" << std::endl;
    MQueue<Student> temp = students;

    while (!temp.empty()) 
    {
        std::cout << temp.front().getUsername() << std::endl;
        temp.pop();
    }
}

// 修改学生在时间队列的情况
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
    std::cout << "学生信息修改成功。" << std::endl;
}

// 输出时间队列学生名单
void TimeSlot::output() const 
{
    std::cout << "当前时间段学生名单：" << std::endl;
    MQueue<Student> temp = students;

    while (!temp.empty())
    {
        std::cout << temp.front().getUsername() << std::endl;
        temp.pop();
    }
}

// 检查指定用户名的学生是否已经入队
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

// 将指定用户名的学生出队
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

// 获取当前时间段的学生数量
size_t TimeSlot::getStudentCount() const 
{
    return students.size();
}
