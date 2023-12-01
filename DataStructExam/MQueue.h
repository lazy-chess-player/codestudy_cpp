// MQueue.h
#ifndef MQUEUE_H
#define MQUEUE_H

#include <vector>

template <typename T>
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
    std::vector<T> elements; // 使用 vector 来存储队列元素
};

// 构造函数
template <typename T>
MQueue<T>::MQueue() {}

// 入队操作
template <typename T>
void MQueue<T>::push(const T& element)
{
    elements.push_back(element);
}

// 出队操作
template <typename T>
void MQueue<T>::pop() 
{
    if (!empty()) 
    {
        elements.erase(elements.begin());
    }
}

// 获取队首元素
template <typename T>
const T& MQueue<T>::front() const 
{
    if (!empty()) 
    {
        return elements[0];
    }
    // 返回一个默认构造的对象，表示队列为空
    static T defaultElement;
    return defaultElement;
}

// 判断队列是否为空
template <typename T>
bool MQueue<T>::empty() const 
{
    return elements.empty();
}

// 获取队列大小
template <typename T>
size_t MQueue<T>::size() const 
{
    return elements.size();
}

#endif // MQUEUE_H
