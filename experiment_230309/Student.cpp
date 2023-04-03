#include "Student.h"


int main()
{
    std::string name, id;
    double chinese_score, math_score, english_score;

    // 从键盘输入学生信息
    std::cout << "请输入学生姓名：";
    std::cin >> name;
    std::cout << "请输入学号：";
    std::cin >> id;
    std::cout << "请输入语文成绩：";
    std::cin >> chinese_score;
    std::cout << "请输入数学成绩：";
    std::cin >> math_score;
    std::cout << "请输入英语成绩：";
    std::cin >> english_score;

    // 创建学生对象
    Student student(name, id, chinese_score, math_score, english_score);

    // 输出学生信息
    student.display();

    return 0;
}