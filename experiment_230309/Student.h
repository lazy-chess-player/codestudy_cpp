#pragma once
#include <iostream>
#include <string>

class Student 
{
public:
    std::string name; // ѧ������
    std::string id; // ѧ��
    double chinese_score; // ���ĳɼ�
    double math_score; // ��ѧ�ɼ�
    double english_score; // Ӣ��ɼ�
    double average_score; // ƽ���ɼ�

    // ���캯��
    Student(std::string name, std::string id, double chinese_score, double math_score, double english_score) {
        this->name = name;
        this->id = id;
        this->chinese_score = chinese_score;
        this->math_score = math_score;
        this->english_score = english_score;
        this->average_score = (chinese_score + math_score + english_score) / 3;
    }

    // ����������ݳ�Աֵ�ĺ���
    void display()
    {
        std::cout << "������" << name << std::endl;
        std::cout << "ѧ�ţ�" << id << std::endl;
        std::cout << "���ĳɼ���" << chinese_score << std::endl;
        std::cout << "��ѧ�ɼ���" << math_score << std::endl;
        std::cout << "Ӣ��ɼ���" << english_score << std::endl;
        std::cout << "ƽ���ɼ���" << average_score << std::endl;
    }
};

