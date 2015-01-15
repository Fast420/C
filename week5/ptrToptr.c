// Yunen He 2014
#include<stdio.h>

int main()
{
	int value1 = 7;
	int value2 = 9;
	int *pointer;
	pointer = &value1;

	int **ppointer1;
	int **ppointer2;

	ppointer1 = &pointer;
	ppointer2 = &pointer;

	printf("%d\n",*ppointer1[0]);
	printf("%d\n",**ppointer2);

	pointer = &value2;

	printf("%d\n",**ppointer1);
	printf("%d\n",**ppointer2);

	return 0;
}