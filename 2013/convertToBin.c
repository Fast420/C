// Yunen He 2014
#include<stdio.h>

#define SIZE 100

int main()
{
	int num = 0;
	int remainder[SIZE];
	int divisor = 2;
	int quotient = -1;
	int index = 0;

	//
	printf("input an integer\n");
	scanf("%d",&num);

	//
	while (quotient != 0)
	{
		quotient = num / divisor;
		remainder[index] = num % divisor;
		index++;

		//
		num = quotient;
	}

	//
	index--;
	while(index >= 0)
	{
		printf("%d",remainder[index]);
		index--;
	}

	printf("\n");
}