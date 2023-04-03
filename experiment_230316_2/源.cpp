#include <iostream>

class Student 
{
public:
    int score;
    static int total_score;
    static int count;

    void account(int s) 
    {
        score = s;
        total_score += s;
        count++;
    }

    static int sum() 
    {
        return total_score;
    }

    static float average() 
    {
        return (float)total_score / count;
    }
};


int Student::total_score = 0;
int Student::count = 0;

int main() 
{
    int cnt = 0;
    std::cout << "ѧ��������";
    std::cin >> cnt;
    std::cout << std::endl;
    int score;
    Student s1;

    while (cnt) 
    {
        std::cin >> score;
        s1.account(score);
        cnt--;
    }

    std::cout << "�ܳɼ��ǣ�" << s1.total_score << std::endl;
    std::cout << "ƽ���ɼ��ǣ�" << s1.average << std::endl;

    return 0;
}
