// Yunen He 2014
#include<stdio.h>

int add(int a, int b);

int add_call_count;

#define MAXSUM 5

int add(int a, int b)
{
	int sum;
	add_call_count++;
	sum = a + b;
	return sum;
} 

int main()
{
	add_call_count = 0;
	printf("one plus one is : %d\n",add(1,1));
	printf("add_call_count: %d\n",add_call_count);
}