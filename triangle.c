#include<stdio.h>
#include<stdlib.h>

int
main()
{
	int height,width;
	height = 0;
	width = 0;

	printf("input the height");
	printf("\n");
	scanf("%d",&height);

	printf("input the width");
	printf("\n");
	scanf("%d",&width);

	if (height >= 4 && width >= 3)
	{
		height -= 2;
		width -= 2;
		printf("+");
		for (int i = 0; i < height; ++i)
		{
			printf("\n");
			printf("|");
			for (int j = 0; j < i; ++j)
			{
				printf(" ");
			}
			printf("\\");
		}
		printf("\n");
		printf("+");
		for (int i = 0; i < width; ++i)
		{
			printf("-");
		}
		printf("+");
	}
}