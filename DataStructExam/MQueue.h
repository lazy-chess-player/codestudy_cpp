// MQueue.h
#ifndef MQUEUE_H
#define MQUEUE_H

#include <vector>

template <typename T>
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
    std::vector<T> elements; // ʹ�� vector ���洢����Ԫ��
};

// ���캯��
template <typename T>
MQueue<T>::MQueue() {}

// ��Ӳ���
template <typename T>
void MQueue<T>::push(const T& element)
{
    elements.push_back(element);
}

// ���Ӳ���
template <typename T>
void MQueue<T>::pop() 
{
    if (!empty()) 
    {
        elements.erase(elements.begin());
    }
}

// ��ȡ����Ԫ��
template <typename T>
const T& MQueue<T>::front() const 
{
    if (!empty()) 
    {
        return elements[0];
    }
    // ����һ��Ĭ�Ϲ���Ķ��󣬱�ʾ����Ϊ��
    static T defaultElement;
    return defaultElement;
}

// �ж϶����Ƿ�Ϊ��
template <typename T>
bool MQueue<T>::empty() const 
{
    return elements.empty();
}

// ��ȡ���д�С
template <typename T>
size_t MQueue<T>::size() const 
{
    return elements.size();
}

#endif // MQUEUE_H
