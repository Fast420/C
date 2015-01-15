#include<stdio.h>
#include<stdlib.h>
// Yunen He

int
main()
{
	int length;
	printf("input the length");
	printf("\n");
	scanf("%d",&length);

	printf("+");
	for (int i = 0; i < length; ++i)
	{
		printf("-");
	}
	printf("+");
	printf("\n");

	for (int i = 0; i < length; ++i)
	{
		printf("|");
		for (int i = 0; i < length; ++i)
		{
			printf(" ");
		}
		printf("|");
		printf("\n");
	}

	printf("+");
	for (int i = 0; i < length; ++i)
	{
		printf("-");
	}
	printf("+");
	printf("\n");
}