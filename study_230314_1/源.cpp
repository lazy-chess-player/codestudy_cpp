#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	int Hash_Map[128];
	char _string[11]; // Ϊ�˴洢�ַ����Ľ�β '\0'�������СӦ����Ϊ 11
	int i;
	char p;

	memset(Hash_Map, 0, sizeof(Hash_Map));

	printf("�����볤��Ϊ10���ַ�����\n");
	fgets(_string, 11, stdin);				// ʹ�� fgets ������ȡ�û�������ַ���
	_string[strcspn(_string, "\n")] = '\0'; // ȥ���ַ�����β�Ļ��з�

	for (i = 0; i < 10; i++)
	{
		printf("%c", _string[i]);
		Hash_Map[_string[i]]++;
	}

	printf("\n��������Ҫ�������ַ���\n");
	scanf(" %c", &p); // ���Ի��з��������ڸ�ʽ�ַ���ǰ��һ���ո�

	printf("%d\n", Hash_Map[p]);

	return 0;
}
/*��δ���������ͳ��һ���ַ������ַ����ִ����ĳ������������£�

����ͷ�ļ� <stdio.h> �� <cstring>��

������һ����СΪ 128 ���������� Hash_Map ��һ����СΪ 10 ���ַ����� _string���Լ�һ�����ͱ��� i ��һ���ַ����� p��

�� memset ������ Hash_Map ���������Ԫ�ض���ʼ��Ϊ 0��

ͨ�� printf ���������ʾ��Ϣ��Ҫ���û�����һ������Ϊ 10 ���ַ�������ͨ�� gets ������ȡ�û�������ַ�����

ʹ�� for ѭ�������ַ��� _string �е�ÿһ���ַ����������� Hash_Map �����ж�Ӧλ�õ�ֵ�� 1���� Hash_Map[_string[i]]++��

ͨ�� printf ���������ʾ��Ϣ��Ҫ���û�������Ҫ�������ַ���

ʹ�� getchar ������ȡ�û�������ַ������� Hash_Map �����в��Ҹ��ַ��ĳ��ִ�������󽫽��ͨ�� printf ���������

�����Ǵ�����޸Ľ��飺

ʹ�� fgets �������� gets ��������Ϊ gets �������ڰ�ȫ�����⡣

�ڻ�ȡ�û�������ַ�ʱ��Ӧ�ú������뻺�����еĻ��з���

�޸ĺ�Ĵ������£�
#include <stdio.h>
#include <string.h>

int main()
{
	int Hash_Map[128];
	char _string[11]; // Ϊ�˴洢�ַ����Ľ�β '\0'�������СӦ����Ϊ 11
	int i;
	char p;

	memset(Hash_Map, 0, sizeof(Hash_Map));

	printf("�����볤��Ϊ10���ַ�����\n");
	fgets(_string, 11, stdin); // ʹ�� fgets ������ȡ�û�������ַ���
	_string[strcspn(_string, "\n")] = '\0'; // ȥ���ַ�����β�Ļ��з�

	for (i = 0; i < 10; i++)
	{
		printf("%c", _string[i]);
		Hash_Map[_string[i]]++;
	}

	printf("\n��������Ҫ�������ַ���\n");
	scanf(" %c", &p); // ���Ի��з��������ڸ�ʽ�ַ���ǰ��һ���ո�

	printf("%d\n", Hash_Map[p]);

	return 0;
}
���У�strcspn ��������������ȡ�ַ����е�һ�����з���λ�ã��Ӷ������滻Ϊ�ַ�����β�� '\0'�����⣬scanf �����ڶ�ȡ�ַ�ʱӦ�ú���ǰ��Ŀհ��ַ�������ᵼ�����뻺�����еĻ��з������롣*/
