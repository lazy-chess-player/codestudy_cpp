#include "Student.h"


int main()
{
    std::string name, id;
    double chinese_score, math_score, english_score;

    // �Ӽ�������ѧ����Ϣ
    std::cout << "������ѧ��������";
    std::cin >> name;
    std::cout << "������ѧ�ţ�";
    std::cin >> id;
    std::cout << "���������ĳɼ���";
    std::cin >> chinese_score;
    std::cout << "��������ѧ�ɼ���";
    std::cin >> math_score;
    std::cout << "������Ӣ��ɼ���";
    std::cin >> english_score;

    // ����ѧ������
    Student student(name, id, chinese_score, math_score, english_score);

    // ���ѧ����Ϣ
    student.display();

    return 0;
}