// InterfaceManager.cpp

#include "InterfaceManager.h"
#include <iostream>

// 清除控制台
void InterfaceManager::clearConsole() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 主程序运行函数
void InterfaceManager::start() 
{
    while (true) 
    {
        clearConsole();
        std::cout << "-----------------------" << std::endl;
        std::cout << "1. 学生登录" << std::endl;
        std::cout << "2. 教师登录" << std::endl;
        std::cout << "3. 注册账号" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "请选择操作：";

        // 输入选择
        int choice;
        std::cin >> choice;

        // 进行选择判断
        switch (choice) 
        {
        case 1: // 学生登录
        {
            std::string username, password;
            std::cout << "请输入学生用户名：";
            std::cin >> username;
            std::cout << "请输入密码：";
            std::cin >> password;

            UserManager::UserType userType = userManager.login(username, password);
            if (userType == UserManager::STUDENT) 
            {
                // 学生登录成功后

                std::cout << "学生登录成功。" << std::endl;

                // 学生功能界面

                std::string studentUsername = username;

                int studentChoice = 0;
                do
                {
                    clearConsole();
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "1. 查询个人预约情况" << std::endl;
                    std::cout << "2. 取消预约" << std::endl;
                    std::cout << "3. 预约实验室" << std::endl;
                    std::cout << "4. 退出" << std::endl;
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "请选择操作：";

                    std::cin >> studentChoice;

                    switch (studentChoice) 
                    {
                    case 1: // 查询个人预约情况
                    {
                        experimentManager.displayStudentReservations(studentUsername);
                        break;
                    }
                    case 2: // 取消预约
                    {
                        std::cout << "已预约的时间段：" << std::endl;
                        experimentManager.displayStudentReservations(studentUsername);

                        int cancelChoice;
                        std::cout << "请输入要取消预约的时间段（1-" << experimentManager.getTimeSlotCount() << "）：";
                        std::cin >> cancelChoice;

                        if (cancelChoice >= 1 && cancelChoice <= experimentManager.getTimeSlotCount()) 
                        {
                            if (experimentManager.cancelReservation(studentUsername, cancelChoice - 1))
                            {
                                std::cout << "取消预约成功。" << std::endl;
                            }
                            else
                            {
                                std::cerr << "取消预约失败。" << std::endl;
                            }
                        }
                        else
                        {
                            std::cerr << "错误：无效的时间段。" << std::endl;
                        }
                        break;
                    }
                    case 3: // 预约实验室
                    {
                        std::cout << "3. 预约实验室" << std::endl;

                        // 显示可选时间段
                        std::cout << "可选时间段：" << std::endl;
                        for (size_t i = 0; i < experimentManager.getTimeSlotCount(); ++i) 
                        {
                            std::cout << i + 1 << ". " << experimentManager.getTimeSlotName(i) << std::endl;
                        }

                        int reserveChoice;
                        std::cout << "请输入要预约的时间段（1-" << experimentManager.getTimeSlotCount() << "）：";
                        std::cin >> reserveChoice;

                        // 检查时间段合法性
                        if (reserveChoice >= 1 && reserveChoice <= experimentManager.getTimeSlotCount())
                        {
                            // 进行预约
                            if (experimentManager.reserveLab(studentUsername, reserveChoice - 1))
                            {
                                std::cout << "预约成功。" << std::endl;
                            }
                            else
                            {
                                std::cout << "预约失败。" << std::endl;
                            }
                        }
                        else
                        {
                            std::cerr << "错误：无效的时间段。" << std::endl;
                        }
                        break;
                    }
                    case 4: //退出
                    {
                        std::cout << "退出学生功能。" << std::endl;
                    }
                        break;
                    default: //其他输入
                    {
                        std::cerr << "错误：无效的选择。" << std::endl;
                    }
                    }
                    system("pause");
                } while (studentChoice != 4);  // 当选择为 4 时退出学生功能界面

            }
            else 
            {
                // 登录失败

                std::cerr << "错误：无效的用户名或密码。" << std::endl;
            }
            break;
        }
        case 2: // 教师登录
        {
            std::string username, password;
            std::cout << "请输入教师用户名：";
            std::cin >> username;
            std::cout << "请输入密码：";
            std::cin >> password;

            UserManager::UserType userType = userManager.login(username, password);
            if (userType == UserManager::TEACHER) 
            {
                // 教师登录成功后

                std::cout << "教师登录成功。" << std::endl;

                // 教师功能界面

                int teacherChoice = 0;
                do 
                {
                    clearConsole();
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "1. 查询所有预约情况" << std::endl;
                    std::cout << "2. 管理预约" << std::endl;
                    std::cout << "3. 退出" << std::endl;
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "请选择操作：";

                    std::cin >> teacherChoice;

                    switch (teacherChoice)
                    {
                    case 1: // 查询所有预约情况
                        for (size_t i = 0; i < experimentManager.getTimeSlotCount(); ++i) 
                        {
                            std::cout << "时间段 " << i + 1 << " (" << experimentManager.getTimeSlotName(i) << "):" << std::endl;
                            experimentManager.query(i);
                        }
                        break;
                    case 2: // 管理预约
                    {
                        std::cout << "管理预约：" << std::endl;
                        for (size_t i = 0; i < experimentManager.getTimeSlotCount(); ++i) 
                        {
                            std::cout << "时间段 " << i + 1 << " (" << experimentManager.getTimeSlotName(i) << "):" << std::endl;
                            experimentManager.query(i);
                        }

                        int manageChoice;
                        std::cout << "请输入要管理的时间段（1-" << experimentManager.getTimeSlotCount() << "）：";
                        std::cin >> manageChoice;

                        if (manageChoice >= 1 && manageChoice <= experimentManager.getTimeSlotCount()) 
                        {
                            std::cout << "1. 取消该时间段所有预约" << std::endl;
                            std::cout << "2. 指定取消某个学生的预约" << std::endl;
                            int manageOption;
                            std::cin >> manageOption;

                            switch (manageOption)
                            {
                            case 1: // 取消该时间段所有预约
                            {
                                experimentManager.deleteStudents(manageChoice - 1);
                                std::cout << "取消该时间段所有预约成功。" << std::endl;
                                break;
                            }
                            case 2: // 指定取消某个学生的预约
                            {
                                std::string studentUsername;
                                std::cout << "请输入要取消预约的学生用户名：";
                                std::cin >> studentUsername;

                                if (experimentManager.cancelReservation(studentUsername, manageChoice - 1)) 
                                {
                                    std::cout << "取消预约成功。" << std::endl;
                                }
                                else 
                                {
                                    std::cerr << "取消预约失败。" << std::endl;
                                }
                                break;
                            }
                            default: //其他输入
                            {
                                std::cerr << "错误：无效的选择。" << std::endl;
                            }
                            }
                        }
                        else 
                        {
                            std::cerr << "错误：无效的时间段。" << std::endl;
                        }
                        break;
                    }
                    case 3: //退出
                    {
                        std::cout << "退出教师功能。" << std::endl;
                        break;
                    }
                    default: //其他输入
                    {
                        std::cerr << "错误：无效的选择。" << std::endl;
                    }
                    }
                    system("pause");
                } while (teacherChoice != 3);  // 当选择为 3 时退出教师功能
            }
            else
            {
                std::cerr << "错误：无效的用户名或密码。" << std::endl;
            }
            break;
        }
        case 3: //用户注册
        {
            //注册界面

            std::cout << "1. 注册学生账户" << std::endl;
            std::cout << "2. 注册教师账户" << std::endl;
            std::cout << "请选择操作：";

            int registerChoice;
            std::cin >> registerChoice;

            switch (registerChoice)
            {
            case 1: //学生注册
            {
                std::string username, password;
                std::cout << "请输入学生用户名：";
                std::cin >> username;
                std::cout << "请输入密码：";
                std::cin >> password;

                if (userManager.registerUser(username, password, UserManager::STUDENT))
                {
                    std::cout << "学生注册成功。" << std::endl;
                }
                else 
                {
                    std::cout << "学生注册失败。" << std::endl;
                }
                break;
            }
            case 2: //教师注册
            {
                std::string username, password, registrationKey;
                std::cout << "请输入教师用户名：";
                std::cin >> username;
                std::cout << "请输入密码：";
                std::cin >> password;
                std::cout << "请输入教师注册密钥：";
                std::cin >> registrationKey;

                if (userManager.registerUser(username, password, UserManager::TEACHER, registrationKey)) 
                {
                    std::cout << "教师注册成功。" << std::endl;
                }
                else
                {
                    std::cout << "教师注册密钥错误" << std::endl;
                    continue;
                }
                break;
            }
            default: //其它输入
                std::cerr << "错误：无效的选择。" << std::endl;
            }
            break;
        }
        case 4: //退出程序
        {
            std::cout << "退出系统。" << std::endl;
            return;
            break;
        }
        default: //其它输入
        {
            std::cerr << "错误：无效的选择。" << std::endl;
            break;
        }
        }
        system("pause");
    }
}
