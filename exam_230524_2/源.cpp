#include <iostream>
#include <string>

using namespace std;

int main()
{
	char str[100] = { '\0' };
	cin.getline(str,100);
	int n = 0;
	while (str[n])
	{
		n++;
	}
	while (n--)
	{
		if (str[n] == ' ')
		{
			for (int i = n + 1; str[i] != ' ' && str[i] != '\0'; i++)
			{
				printf("%c", str[i]);
			}
			printf("%c", ' ');
		}
		else if(n == 0)
		{
			for (int i = n; str[i] != ' ' && str[i] != '\0'; i++)
			{
				printf("%c", str[i]);
			}
		}
	}
	return 0;
}