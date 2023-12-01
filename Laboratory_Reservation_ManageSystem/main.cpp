#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// 队列模板

template <typename T, size_t MaxSize>
class MQueue
{
public:
    MQueue(); // 构造函数
    void push(const T& element); // 入队操作
    void pop(); // 出队操作
    const T& front() const; // 获取队首元素
    bool empty() const; // 判断队列是否为空
    size_t size() const; // 获取队列大小

private:
    T elements[MaxSize]; // 使用数组来存储队列元素
    size_t frontIndex; // 队首索引
    size_t rearIndex; // 队尾索引
    size_t currentSize; // 当前队列大小
};

// 构造函数
template <typename T, size_t MaxSize>
MQueue<T, MaxSize>::MQueue() : frontIndex(0), rearIndex(0), currentSize(0) {}

// 入队操作
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
        // 队列已满，无法入队
        assert("队列已满" && false);
        return;
    }
}

// 出队操作
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
        // 队列为空，无法出队
        assert("队列为空" && false);
        return;
    }
}

// 获取队首元素
template <typename T, size_t MaxSize>
const T& MQueue<T, MaxSize>::front() const
{
    if (!empty())
    {
        return elements[frontIndex];
    }
    // 返回一个默认构造的对象，表示队列为空
    static T defaultElement;
    return defaultElement;
}

// 判断队列是否为空
template <typename T, size_t MaxSize>
bool MQueue<T, MaxSize>::empty() const
{
    return currentSize == 0;
}

// 获取队列大小
template <typename T, size_t MaxSize>
size_t MQueue<T, MaxSize>::size() const
{
    return currentSize;
}


// 全局变量
std::vector<MQueue<std::string,5>> timeSlots(3);  // 三个时间槽，每个槽使用队列存储预约学生名单

// 函数声明
void start(); // 主程序运行
void mainMenu(); // 主菜单
void reservationMenu(); // 预约菜单
void insertReservation(int timeSlotIndex, const std::string& username); // 插入预约
void deleteReservation(int timeSlotIndex); // 删除预约
void queryReservations(int timeSlotIndex); // 查询预约
void modifyReservation(); // 修改预约
void outputReservations();  // 输出预约名单

// 主程序运行
void start()
{
    mainMenu();
}

// 主菜单
void mainMenu()
{
    int mainMenuChoice;

    do
    {
        system("cls");
        std::cout << "  物理实验室管理系统  " << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "1、预约实验室" << std::endl;
        std::cout << "2、取消预约" << std::endl;
        std::cout << "3、查询所有预约" << std::endl;
        std::cout << "4、修改预约" << std::endl;
        std::cout << "5、输出预约名单" << std::endl;
        std::cout << "6、退出" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "请选择：";
        std::cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
        case 1:
            reservationMenu();
            break;
        case 2:
            std::cout << "请选择要取消预约的时间段（1表示时间一，2表示时间二，3表示时间三）：";
            int cancelTimeSlot;
            std::cin >> cancelTimeSlot;
            deleteReservation(cancelTimeSlot - 1); // 时间槽索引从0开始
            break;
        case 3:
            std::cout << "请选择要查询的时间段（1表示时间一，2表示时间二，3表示时间三）：";
            int queryTimeSlot;
            std::cin >> queryTimeSlot;
            queryReservations(queryTimeSlot - 1); // 时间槽索引从0开始
            break;
        case 4:
            modifyReservation();
            break;
        case 5:
            outputReservations();
            break;
        case 6:
            std::cout << "退出系统" << std::endl;
            break;
        default:
            std::cout << "错误选项" << std::endl;
            break;
        }
        system("pause");
    } while (mainMenuChoice != 6);
}

// 预约菜单
void reservationMenu()
{
    std::string username;
    int timeSlotIndex;

    std::cout << "请输入您的用户名：";
    std::cin >> username;

    std::cout << "请选择时间段（1表示时间一，2表示时间二，3表示时间三）：";
    std::cin >> timeSlotIndex;

    // 将时间槽索引调整为合法值
    timeSlotIndex = std::max(1, std::min(3, timeSlotIndex));

    insertReservation(timeSlotIndex - 1, username); // 时间槽索引从0开始
}

// 插入预约
void insertReservation(int timeSlotIndex, const std::string& username)
{
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size() && timeSlots[timeSlotIndex].size() <= 5)
    {
        timeSlots[timeSlotIndex].push(username);
        std::cout << "预约成功！" << std::endl;
    }
    else
    {
        std::cout << "无效的时间段" << std::endl;
    }
}

// 删除预约
void deleteReservation(int timeSlotIndex)
{
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size() && !timeSlots[timeSlotIndex].empty())
    {
        timeSlots[timeSlotIndex].pop();
        std::cout << "取消预约成功！" << std::endl;
    }
    else
    {
        std::cout << "无效的时间段或没有预约记录" << std::endl;
    }
}

// 查询预约
void queryReservations(int timeSlotIndex)
{
    if (timeSlotIndex >= 0 && timeSlotIndex < timeSlots.size())
    {
        std::cout << "时间段 " << timeSlotIndex + 1 << " 的预约名单：" << std::endl;
        MQueue<std::string,5> copyQueue = timeSlots[timeSlotIndex]; // 为了不改变原队列，使用副本输出
        while (!copyQueue.empty())
        {
            std::cout << copyQueue.front() << std::endl;
            copyQueue.pop();
        }
    }
    else
    {
        std::cout << "无效的时间段" << std::endl;
    }
}

// 修改预约
void modifyReservation()
{
    std::string username;
    int originalTimeSlot, newTimeSlot;

    std::cout << "请输入您的用户名：";
    std::cin >> username;

    std::cout << "请选择原预约的时间段（1表示时间一，2表示时间二，3表示时间三）：";
    std::cin >> originalTimeSlot;

    std::cout << "请选择新的时间段（1表示时间一，2表示时间二，3表示时间三）：";
    std::cin >> newTimeSlot;

    // 将时间槽索引调整为合法值
    originalTimeSlot = std::max(1, std::min(3, originalTimeSlot));
    newTimeSlot = std::max(1, std::min(3, newTimeSlot));

    // 先取消原有的预约
    deleteReservation(originalTimeSlot - 1);

    // 再进行新的预约
    insertReservation(newTimeSlot - 1, username);
}

// 输出预约名单
void outputReservations()
{
    for (int i = 0; i < timeSlots.size(); ++i)
    {
        std::cout << "时间段 " << i + 1 << " 的预约名单：" << std::endl;
        MQueue<std::string,5> copyQueue = timeSlots[i]; // 为了不改变原队列，使用副本输出
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
