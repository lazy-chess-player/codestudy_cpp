#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int x;
    printf("������ѧ���ɼ���");
    scanf("%d", &x);
    if (x < 60)
        printf("bad");
    else if (60 <= x && x < 80)
        printf("middle");
    else if (80 <= x && x < 90)
        printf("good");
    else
        printf("excellent");
    return 0;
}