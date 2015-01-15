// Yunen He 2014
#include<stdio.h>

#define NUMLEN 1000

int main()
{
	int numlist[NUMLEN];
	int num = 0;
	int index = 0;
	int i = 0;
	int sum = 0;

	while(num != -1)
	{
		scanf("%d",&num);
		numlist[index] = num;
		index++;
	}

	// sum up
	for (i = 0; i < index; i++)
	{
		sum += numlist[i];
	}

	//
	printf("totoal : %d\n",sum);

	return 0;
}