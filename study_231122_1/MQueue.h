// MQueue.h

#include <cassert>

#ifndef MQUEUE_H
#define MQUEUE_H

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

#endif // MQUEUE_H
