// InterfaceManager.h

#ifndef INTERFACE_MANAGER_H
#define INTERFACE_MANAGER_H

#include "UserManager.h"
#include "ExperimentManager.h"

class InterfaceManager
{
public:

    // ���������к���
    void start();

    // �������̨
    void clearConsole();

private:

    // �����û�����ģ��
    UserManager userManager;

    // ����ʵ���Ҳ���ģ��
    ExperimentManager experimentManager;

};

#endif // INTERFACE_MANAGER_H
