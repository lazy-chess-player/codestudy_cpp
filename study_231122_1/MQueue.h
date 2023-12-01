// MQueue.h

#include <cassert>

#ifndef MQUEUE_H
#define MQUEUE_H

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

#endif // MQUEUE_H
