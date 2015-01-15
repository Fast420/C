#include<stdio.h>
#include<stdlib.h>
int
main()
{
	int a[100];
	int value,i,size;
	scanf("%d",&value);

	size = 0;
	i = 0;
	if (value == 0)
	{
		printf("%d", 0);
		printf("\n");
	}
	else
	{
		while(value != 0)
	{
		a[size] = value % 3;
		value = value / 3;
		size++;
	}
	size = size - 1;
	for (int i = size; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	}
}