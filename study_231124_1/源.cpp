#include <iostream>

int main() 
{
	for (int i = 1; i < 10; i++) 
	{
		for (int j = 1; j <= i; j++) 
		{
			printf("%2d*%2d=%2d ",i,j,i*j); 
		}
		printf("\n"); 
	}
	return 0; 
}