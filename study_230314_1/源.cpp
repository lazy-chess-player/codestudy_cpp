#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	int Hash_Map[128];
	char _string[11]; // 为了存储字符串的结尾 '\0'，数组大小应该设为 11
	int i;
	char p;

	memset(Hash_Map, 0, sizeof(Hash_Map));

	printf("请输入长度为10的字符串：\n");
	fgets(_string, 11, stdin);				// 使用 fgets 函数获取用户输入的字符串
	_string[strcspn(_string, "\n")] = '\0'; // 去掉字符串结尾的换行符

	for (i = 0; i < 10; i++)
	{
		printf("%c", _string[i]);
		Hash_Map[_string[i]]++;
	}

	printf("\n请输入需要检索的字符：\n");
	scanf(" %c", &p); // 忽略换行符，可以在格式字符串前加一个空格

	printf("%d\n", Hash_Map[p]);

	return 0;
}
/*这段代码是用来统计一个字符串中字符出现次数的程序，其流程如下：

包含头文件 <stdio.h> 和 <cstring>。

定义了一个大小为 128 的整型数组 Hash_Map 和一个大小为 10 的字符数组 _string，以及一个整型变量 i 和一个字符变量 p。

用 memset 函数将 Hash_Map 数组的所有元素都初始化为 0。

通过 printf 函数输出提示信息，要求用户输入一个长度为 10 的字符串，并通过 gets 函数获取用户输入的字符串。

使用 for 循环遍历字符串 _string 中的每一个字符，并将其在 Hash_Map 数组中对应位置的值加 1，即 Hash_Map[_string[i]]++。

通过 printf 函数输出提示信息，要求用户输入需要检索的字符。

使用 getchar 函数获取用户输入的字符，并在 Hash_Map 数组中查找该字符的出现次数，最后将结果通过 printf 函数输出。

以下是代码的修改建议：

使用 fgets 函数代替 gets 函数，因为 gets 函数存在安全性问题。

在获取用户输入的字符时，应该忽略输入缓冲区中的换行符。

修改后的代码如下：
#include <stdio.h>
#include <string.h>

int main()
{
	int Hash_Map[128];
	char _string[11]; // 为了存储字符串的结尾 '\0'，数组大小应该设为 11
	int i;
	char p;

	memset(Hash_Map, 0, sizeof(Hash_Map));

	printf("请输入长度为10的字符串：\n");
	fgets(_string, 11, stdin); // 使用 fgets 函数获取用户输入的字符串
	_string[strcspn(_string, "\n")] = '\0'; // 去掉字符串结尾的换行符

	for (i = 0; i < 10; i++)
	{
		printf("%c", _string[i]);
		Hash_Map[_string[i]]++;
	}

	printf("\n请输入需要检索的字符：\n");
	scanf(" %c", &p); // 忽略换行符，可以在格式字符串前加一个空格

	printf("%d\n", Hash_Map[p]);

	return 0;
}
其中，strcspn 函数可以用来获取字符串中第一个换行符的位置，从而将其替换为字符串结尾符 '\0'。另外，scanf 函数在读取字符时应该忽略前面的空白字符，否则会导致输入缓冲区中的换行符被读入。*/
