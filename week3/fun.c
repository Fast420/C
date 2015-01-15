// Yunen He 2014
#include<stdio.h>

int main()
{
	int x = 0;
	int y = 0;

	(x = 2) && (y = 1);

	printf("2 1\n");
	printf("%d %d\n",x,y);
}