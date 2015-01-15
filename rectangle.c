#include<stdio.h>
#include<stdlib.h>
// Yunen He
int
main()
{
	int width,height;
	printf("input the width");
	printf("\n");
	scanf("%d",&width);

	printf("input the height");
	printf("\n");
	scanf("%d",&height);

	printf("+");
	for (int i = 0; i < width; ++i)
	{
		printf("-");
	}
	printf("+");
	printf("\n");

	if (height >= 3)
	{
		for (int i = 0; i < height; ++i)
		{
		printf("|");
		for (int i = 0; i < width; ++i)
		{
			printf(" ");
		}
		printf("|");
		printf("\n");
		}
	}

	printf("+");
	for (int i = 0; i < width; ++i)
	{
		printf("-");
	}
	printf("+");
	printf("\n");
}