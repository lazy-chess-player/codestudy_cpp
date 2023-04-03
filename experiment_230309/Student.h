#pragma once
#include <iostream>
#include <string>

class Student 
{
public:
    std::string name; // 学生姓名
    std::string id; // 学号
    double chinese_score; // 语文成绩
    double math_score; // 数学成绩
    double english_score; // 英语成绩
    double average_score; // 平均成绩

    // 构造函数
    Student(std::string name, std::string id, double chinese_score, double math_score, double english_score) {
        this->name = name;
        this->id = id;
        this->chinese_score = chinese_score;
        this->math_score = math_score;
        this->english_score = english_score;
        this->average_score = (chinese_score + math_score + english_score) / 3;
    }

    // 输出所有数据成员值的函数
    void display()
    {
        std::cout << "姓名：" << name << std::endl;
        std::cout << "学号：" << id << std::endl;
        std::cout << "语文成绩：" << chinese_score << std::endl;
        std::cout << "数学成绩：" << math_score << std::endl;
        std::cout << "英语成绩：" << english_score << std::endl;
        std::cout << "平均成绩：" << average_score << std::endl;
    }
};

