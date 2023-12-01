#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// ����ģ��

template <typename T, size_t MaxSize>
class MQueue
{
public:
    MQueue(); // ���캯��
    void push(const T& element); // ��Ӳ���
    void pop(); // ���Ӳ���
    const T& front() const; // ��ȡ����Ԫ��
    bool empty() const; // �ж϶����Ƿ�Ϊ��
    size_t size() const; // ��ȡ���д�С

private:
    T elements[MaxSize]; // ʹ���������洢����Ԫ��
    size_t frontIndex; // ��������
    size_t rearIndex; // ��β����
    size_t currentSize; // ��ǰ���д�С
};

// ���캯��
template <typename T, size_t MaxSize>
MQueue<T, MaxSize>::MQueue() : frontIndex(0), rearIndex(0), currentSize(0) {}

// ��Ӳ���
template <typename T, size_t MaxSize>
void MQueue<T, MaxSize>::push(const T& element)
{
    if (currentSize < MaxSize)
    {
        elements[rearIndex] = element;
        rearIndex = (rearIndex + 1) % MaxSize;
        currentSize++;
    }
    else
    {
        // �����������޷����
        assert("��������" && false);
        return;
    }
}

// ���Ӳ���
template <typename T, size_t MaxSize>
void MQueue<T, MaxSize>::pop()
{
    if (!empty())
    {
        frontIndex = (frontIndex + 1) % MaxSize;
        currentSize--;
    }
    else
    {
        // ����Ϊ�գ��޷�����
        assert("����Ϊ��" && false);
        return;
    }
}

// ��ȡ����Ԫ��
template <typename T, size_t MaxSize>
const T& MQueue<T, MaxSize>::front() const
{
    if (!empty())
    {
        return elements[frontIndex];
    }
    // ����һ��Ĭ�Ϲ���Ķ��󣬱�ʾ����Ϊ��
    static T defaultElement;
    return defaultElement;
}

// �ж϶����Ƿ�Ϊ��
template <typename T, size_t MaxSize>
bool MQueue<T, MaxSize>::empty() const
{
    return currentSize == 0;
}

// ��ȡ���д�С
template <typename T, size_t MaxSize>
size_t MQueue<T, MaxSize>::size() const
{
    return currentSize;
}


// ȫ�ֱ���
std::vector<MQueue<std::string,5>> timeSlots(3);  // ����ʱ��ۣ�ÿ����ʹ�ö��д洢ԤԼѧ������

// ��������
void start(); // ����������
void mainMenu(); // ���˵�
void reservationMenu(); // ԤԼ�˵�
void insertReservation(int timeSlotIndex, const std::string& username); // ����ԤԼ
void deleteReservation(int timeSlotIndex); // ɾ��ԤԼ
void queryReservations(int timeSlotIndex); // ��ѯԤԼ
void modifyReservation(); // �޸�ԤԼ
void outputReservations();  // ���ԤԼ����

// ����������
void start()
{
    mainMenu();
}

// ���˵�
void mainMenu()
{
    int mainMenuChoice;

    do
    {
        system("cls");
        std::cout << "  ����ʵ���ҹ���ϵͳ  " << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "1��ԤԼʵ����" << std::endl;
        std::cout << "2��ȡ��ԤԼ" << std::endl;
        std::cout << "3����ѯ����ԤԼ" << std::endl;
        std::cout << "4���޸�ԤԼ" << std::endl;
        std::cout << "5�����ԤԼ����" << std::endl;
        std::cout << "6���˳�" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "��ѡ��";
        std::cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
        case 1:
            reservationMenu();
            break;
        case 2:
            std::cout << "��ѡ��Ҫȡ��ԤԼ��ʱ��Σ�1��ʾʱ��һ��2��ʾʱ�����3��ʾʱ��������";
            int cancelTimeSlot;
            std::cin >> cancelTimeSlot;
            deleteReservation(cancelTimeSlot - 1); // ʱ���������0��ʼ
            break;
        case 3:
            std::cout << "��ѡ��Ҫ��ѯ��ʱ��Σ�1��ʾʱ��һ��2��ʾʱ�����3��ʾʱ��������";
            int queryTimeSlot;
            std::cin >> queryTimeSlot;
            queryReservations(queryTimeSlot - 1); // ʱ���������0��ʼ
            break;
        case 4:
            modifyReservation();
            break;
        case 5:
            outputReservations();
            break;
        case 6:
            std::cout << "�˳�ϵͳ" << std::endl;
            break;
        default:
            std::cout << "����ѡ��" << std::endl;
            break;
        }
        system("pause");
    } while (mainMenuChoice != 6);
}

// ԤԼ�˵�
void reservationMenu()
{
    std::string username;
    int timeSlotIndex;

    std::cout << "�����������û�����";
    std::cin >> username;

    std::cout << "��ѡ��ʱ��Σ�1��ʾʱ��һ��2��ʾʱ�����3��ʾʱ��������";
    std::cin >> timeSlotIndex;

    // ��ʱ�����������Ϊ�Ϸ�ֵ
    timeSlotIndex = std::max(1, std::min(3, timeSlotIndex));

    insertReservation(timeSlotIndex - 1, username); // ʱ���������0��ʼ
}

// ����ԤԼ
void insertReservation(int timeSlotIndex, const std::string& username)
{
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size() && timeSlots[timeSlotIndex].size() <= 5)
    {
        timeSlots[timeSlotIndex].push(username);
        std::cout << "ԤԼ�ɹ���" << std::endl;
    }
    else
    {
        std::cout << "��Ч��ʱ���" << std::endl;
    }
}

// ɾ��ԤԼ
void deleteReservation(int timeSlotIndex)
{
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size() && !timeSlots[timeSlotIndex].empty())
    {
        timeSlots[timeSlotIndex].pop();
        std::cout << "ȡ��ԤԼ�ɹ���" << std::endl;
    }
    else
    {
        std::cout << "��Ч��ʱ��λ�û��ԤԼ��¼" << std::endl;
    }
}

// ��ѯԤԼ
void queryReservations(int timeSlotIndex)
{
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        std::cout << "ʱ��� " << timeSlotIndex + 1 << " ��ԤԼ������" << std::endl;
        MQueue<std::string,5> copyQueue = timeSlots[timeSlotIndex]; // Ϊ�˲��ı�ԭ���У�ʹ�ø������
        while (!copyQueue.empty())
        {
            std::cout << copyQueue.front() << std::endl;
            copyQueue.pop();
        }
    }
    else
    {
        std::cout << "��Ч��ʱ���" << std::endl;
    }
}

// �޸�ԤԼ
void modifyReservation()
{
    std::string username;
    int originalTimeSlot, newTimeSlot;

    std::cout << "�����������û�����";
    std::cin >> username;

    std::cout << "��ѡ��ԭԤԼ��ʱ��Σ�1��ʾʱ��һ��2��ʾʱ�����3��ʾʱ��������";
    std::cin >> originalTimeSlot;

    std::cout << "��ѡ���µ�ʱ��Σ�1��ʾʱ��һ��2��ʾʱ�����3��ʾʱ��������";
    std::cin >> newTimeSlot;

    // ��ʱ�����������Ϊ�Ϸ�ֵ
    originalTimeSlot = std::max(1, std::min(3, originalTimeSlot));
    newTimeSlot = std::max(1, std::min(3, newTimeSlot));

    // ��ȡ��ԭ�е�ԤԼ
    deleteReservation(originalTimeSlot - 1);

    // �ٽ����µ�ԤԼ
    insertReservation(newTimeSlot - 1, username);
}

// ���ԤԼ����
void outputReservations()
{
    for (int i = 0; i < timeSlots.size(); ++i)
    {
        std::cout << "ʱ��� " << i + 1 << " ��ԤԼ������" << std::endl;
        MQueue<std::string,5> copyQueue = timeSlots[i]; // Ϊ�˲��ı�ԭ���У�ʹ�ø������
        while (!copyQueue.empty())
        {
            std::cout << copyQueue.front() << std::endl;
            copyQueue.pop();
        }
        std::cout << "----------------------" << std::endl;
    }
}

int main()
{
    start();
    return 0;
}
