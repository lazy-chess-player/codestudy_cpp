// InterfaceManager.cpp

#include "InterfaceManager.h"
#include <iostream>

// �������̨
void InterfaceManager::clearConsole() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ���������к���
void InterfaceManager::start() 
{
    while (true) 
    {
        clearConsole();
        std::cout << "-----------------------" << std::endl;
        std::cout << "1. ѧ����¼" << std::endl;
        std::cout << "2. ��ʦ��¼" << std::endl;
        std::cout << "3. ע���˺�" << std::endl;
        std::cout << "4. �˳�" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "��ѡ�������";

        // ����ѡ��
        int choice;
        std::cin >> choice;

        // ����ѡ���ж�
        switch (choice) 
        {
        case 1: // ѧ����¼
        {
            std::string username, password;
            std::cout << "������ѧ���û�����";
            std::cin >> username;
            std::cout << "���������룺";
            std::cin >> password;

            UserManager::UserType userType = userManager.login(username, password);
            if (userType == UserManager::STUDENT) 
            {
                // ѧ����¼�ɹ���

                std::cout << "ѧ����¼�ɹ���" << std::endl;

                // ѧ�����ܽ���

                std::string studentUsername = username;

                int studentChoice = 0;
                do
                {
                    clearConsole();
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "1. ��ѯ����ԤԼ���" << std::endl;
                    std::cout << "2. ȡ��ԤԼ" << std::endl;
                    std::cout << "3. ԤԼʵ����" << std::endl;
                    std::cout << "4. �˳�" << std::endl;
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "��ѡ�������";

                    std::cin >> studentChoice;

                    switch (studentChoice) 
                    {
                    case 1: // ��ѯ����ԤԼ���
                    {
                        experimentManager.displayStudentReservations(studentUsername);
                        break;
                    }
                    case 2: // ȡ��ԤԼ
                    {
                        std::cout << "��ԤԼ��ʱ��Σ�" << std::endl;
                        experimentManager.displayStudentReservations(studentUsername);

                        int cancelChoice;
                        std::cout << "������Ҫȡ��ԤԼ��ʱ��Σ�1-" << experimentManager.getTimeSlotCount() << "����";
                        std::cin >> cancelChoice;

                        if (cancelChoice >= 1 && cancelChoice <= experimentManager.getTimeSlotCount()) 
                        {
                            if (experimentManager.cancelReservation(studentUsername, cancelChoice - 1))
                            {
                                std::cout << "ȡ��ԤԼ�ɹ���" << std::endl;
                            }
                            else
                            {
                                std::cerr << "ȡ��ԤԼʧ�ܡ�" << std::endl;
                            }
                        }
                        else
                        {
                            std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
                        }
                        break;
                    }
                    case 3: // ԤԼʵ����
                    {
                        std::cout << "3. ԤԼʵ����" << std::endl;

                        // ��ʾ��ѡʱ���
                        std::cout << "��ѡʱ��Σ�" << std::endl;
                        for (size_t i = 0; i < experimentManager.getTimeSlotCount(); ++i) 
                        {
                            std::cout << i + 1 << ". " << experimentManager.getTimeSlotName(i) << std::endl;
                        }

                        int reserveChoice;
                        std::cout << "������ҪԤԼ��ʱ��Σ�1-" << experimentManager.getTimeSlotCount() << "����";
                        std::cin >> reserveChoice;

                        // ���ʱ��κϷ���
                        if (reserveChoice >= 1 && reserveChoice <= experimentManager.getTimeSlotCount())
                        {
                            // ����ԤԼ
                            if (experimentManager.reserveLab(studentUsername, reserveChoice - 1))
                            {
                                std::cout << "ԤԼ�ɹ���" << std::endl;
                            }
                            else
                            {
                                std::cout << "ԤԼʧ�ܡ�" << std::endl;
                            }
                        }
                        else
                        {
                            std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
                        }
                        break;
                    }
                    case 4: //�˳�
                    {
                        std::cout << "�˳�ѧ�����ܡ�" << std::endl;
                    }
                        break;
                    default: //��������
                    {
                        std::cerr << "������Ч��ѡ��" << std::endl;
                    }
                    }
                    system("pause");
                } while (studentChoice != 4);  // ��ѡ��Ϊ 4 ʱ�˳�ѧ�����ܽ���

            }
            else 
            {
                // ��¼ʧ��

                std::cerr << "������Ч���û��������롣" << std::endl;
            }
            break;
        }
        case 2: // ��ʦ��¼
        {
            std::string username, password;
            std::cout << "�������ʦ�û�����";
            std::cin >> username;
            std::cout << "���������룺";
            std::cin >> password;

            UserManager::UserType userType = userManager.login(username, password);
            if (userType == UserManager::TEACHER) 
            {
                // ��ʦ��¼�ɹ���

                std::cout << "��ʦ��¼�ɹ���" << std::endl;

                // ��ʦ���ܽ���

                int teacherChoice = 0;
                do 
                {
                    clearConsole();
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "1. ��ѯ����ԤԼ���" << std::endl;
                    std::cout << "2. ����ԤԼ" << std::endl;
                    std::cout << "3. �˳�" << std::endl;
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "��ѡ�������";

                    std::cin >> teacherChoice;

                    switch (teacherChoice)
                    {
                    case 1: // ��ѯ����ԤԼ���
                        for (size_t i = 0; i < experimentManager.getTimeSlotCount(); ++i) 
                        {
                            std::cout << "ʱ��� " << i + 1 << " (" << experimentManager.getTimeSlotName(i) << "):" << std::endl;
                            experimentManager.query(i);
                        }
                        break;
                    case 2: // ����ԤԼ
                    {
                        std::cout << "����ԤԼ��" << std::endl;
                        for (size_t i = 0; i < experimentManager.getTimeSlotCount(); ++i) 
                        {
                            std::cout << "ʱ��� " << i + 1 << " (" << experimentManager.getTimeSlotName(i) << "):" << std::endl;
                            experimentManager.query(i);
                        }

                        int manageChoice;
                        std::cout << "������Ҫ�����ʱ��Σ�1-" << experimentManager.getTimeSlotCount() << "����";
                        std::cin >> manageChoice;

                        if (manageChoice >= 1 && manageChoice <= experimentManager.getTimeSlotCount()) 
                        {
                            std::cout << "1. ȡ����ʱ�������ԤԼ" << std::endl;
                            std::cout << "2. ָ��ȡ��ĳ��ѧ����ԤԼ" << std::endl;
                            int manageOption;
                            std::cin >> manageOption;

                            switch (manageOption)
                            {
                            case 1: // ȡ����ʱ�������ԤԼ
                            {
                                experimentManager.deleteStudents(manageChoice - 1);
                                std::cout << "ȡ����ʱ�������ԤԼ�ɹ���" << std::endl;
                                break;
                            }
                            case 2: // ָ��ȡ��ĳ��ѧ����ԤԼ
                            {
                                std::string studentUsername;
                                std::cout << "������Ҫȡ��ԤԼ��ѧ���û�����";
                                std::cin >> studentUsername;

                                if (experimentManager.cancelReservation(studentUsername, manageChoice - 1)) 
                                {
                                    std::cout << "ȡ��ԤԼ�ɹ���" << std::endl;
                                }
                                else 
                                {
                                    std::cerr << "ȡ��ԤԼʧ�ܡ�" << std::endl;
                                }
                                break;
                            }
                            default: //��������
                            {
                                std::cerr << "������Ч��ѡ��" << std::endl;
                            }
                            }
                        }
                        else 
                        {
                            std::cerr << "������Ч��ʱ��Ρ�" << std::endl;
                        }
                        break;
                    }
                    case 3: //�˳�
                    {
                        std::cout << "�˳���ʦ���ܡ�" << std::endl;
                        break;
                    }
                    default: //��������
                    {
                        std::cerr << "������Ч��ѡ��" << std::endl;
                    }
                    }
                    system("pause");
                } while (teacherChoice != 3);  // ��ѡ��Ϊ 3 ʱ�˳���ʦ����
            }
            else
            {
                std::cerr << "������Ч���û��������롣" << std::endl;
            }
            break;
        }
        case 3: //�û�ע��
        {
            //ע�����

            std::cout << "1. ע��ѧ���˻�" << std::endl;
            std::cout << "2. ע���ʦ�˻�" << std::endl;
            std::cout << "��ѡ�������";

            int registerChoice;
            std::cin >> registerChoice;

            switch (registerChoice)
            {
            case 1: //ѧ��ע��
            {
                std::string username, password;
                std::cout << "������ѧ���û�����";
                std::cin >> username;
                std::cout << "���������룺";
                std::cin >> password;

                if (userManager.registerUser(username, password, UserManager::STUDENT))
                {
                    std::cout << "ѧ��ע��ɹ���" << std::endl;
                }
                else 
                {
                    std::cout << "ѧ��ע��ʧ�ܡ�" << std::endl;
                }
                break;
            }
            case 2: //��ʦע��
            {
                std::string username, password, registrationKey;
                std::cout << "�������ʦ�û�����";
                std::cin >> username;
                std::cout << "���������룺";
                std::cin >> password;
                std::cout << "�������ʦע����Կ��";
                std::cin >> registrationKey;

                if (userManager.registerUser(username, password, UserManager::TEACHER, registrationKey)) 
                {
                    std::cout << "��ʦע��ɹ���" << std::endl;
                }
                else
                {
                    std::cout << "��ʦע����Կ����" << std::endl;
                    continue;
                }
                break;
            }
            default: //��������
                std::cerr << "������Ч��ѡ��" << std::endl;
            }
            break;
        }
        case 4: //�˳�����
        {
            std::cout << "�˳�ϵͳ��" << std::endl;
            return;
            break;
        }
        default: //��������
        {
            std::cerr << "������Ч��ѡ��" << std::endl;
            break;
        }
        }
        system("pause");
    }
}
