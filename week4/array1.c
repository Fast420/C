// Yunen He 2014
/** 
Exersizes Write a program that loads a list of integers form standard input into an array 
and that finds the maximum and minimum values from this array.
**/

#include<stdio.h>
#define size 10

int main() 
{
	//int a[size];
	int  max_num = 0;
	int  min_num = 0;
	int p_num = 0;
	int c_num = 0;
/**
	printf("Enter 10 integers\n");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",&num);
		a[i] = num;
	}
**/
	int a[] = {22,71,65,28,65,30,18,0,41,56};

	for (int i = 0; i < size; ++i)
	{
		if (i == 0)
			p_num = a[i];
		else
		{
			c_num = a[i];
			if (c_num > p_num)
			{
				p_num = c_num;
			}
		}
	}
	max_num = p_num;

	p_num = 0;
		for (int i = 0; i < size; ++i)
	{
		if (i == 0)
			p_num = a[i];
		else
		{
			c_num = a[i];
			if (c_num < p_num)
			{
				p_num = c_num;
			}
		}
	}
	min_num = p_num;
	printf("maximum: %d\n",max_num);
	printf("minimum: %d\n",min_num);
}