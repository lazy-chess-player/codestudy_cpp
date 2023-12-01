#include <iostream>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode, * ListP;

struct ListNode* partition(struct ListNode* head, int x)
{
    /*存储比x大的数据*/
    struct ListNode* bigger_head = NULL;
    struct ListNode* bigger = bigger_head;
    /*存储比x小的数据*/
    struct ListNode* smaller_head = NULL;
    struct ListNode* smaller = smaller_head;
    /*遍历链表*/
    struct ListNode* cur = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (cur)
    {
        if (cur->val >= x)
        {
            if (bigger_head == NULL)
            {
                bigger_head = cur;
                bigger = bigger_head;
            }
            else
            {
                bigger->next = cur;
                bigger = bigger->next;
            }
        }
        else
        {
            if (smaller_head == NULL)
            {
                smaller_head = cur;
                smaller = smaller_head;
            }
            else
            {
                smaller->next = cur;
                smaller = smaller->next;
            }
        }
        cur = cur->next;
    }
    if (bigger_head == NULL || smaller_head == NULL)
    {
        return head;
    }
    else
    {
        smaller->next = bigger_head;
        return smaller_head;
    }
}

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* less_head = NULL;
    struct ListNode* less = NULL;
    struct ListNode* more_head = NULL;
    struct ListNode* more = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        if (cur->val < x) 
        {
            if (!less_head)
            {
                less_head = cur;
                less = cur;
            }
            else
            {
                less->next = cur;
                less = less->next;
            }
        }
        else 
        {
            if (!more_head) 
            {
                more_head = cur;
                more = cur;
            }
            else 
            {
                more->next = cur;
                more = more->next;
            }
        }
        cur = cur->next;
    }

    if (!less_head)
        return more_head;

    less->next = more_head;

    if (more)
        more->next = NULL;

    return less_head;
}