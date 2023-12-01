// InterfaceManager.h

#ifndef INTERFACE_MANAGER_H
#define INTERFACE_MANAGER_H

#include "UserManager.h"
#include "ExperimentManager.h"

class InterfaceManager
{
public:

    // 主程序运行函数
    void start();

    // 清理控制台
    void clearConsole();

private:

    // 调用用户操作模块
    UserManager userManager;

    // 调用实验室操作模块
    ExperimentManager experimentManager;

};

#endif // INTERFACE_MANAGER_H
