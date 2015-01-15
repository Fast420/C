#include<stdio.h>
#include<stdlib.h>

int
main()
{
	int base,power,num;

	num = 3;
	base = 3;
	power = 2;

	if (power == 0)
	{
		num = 1;
	}
	else
	{
		for (int i = 0; i < power - 1; i++)
		{
			num = num * base;
		}
	}

	printf("%d", num);
	printf("\n");
}