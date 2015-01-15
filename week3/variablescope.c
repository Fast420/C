// Yunen He 2014
#include<stdio.h>

int total_count;
static int total_sum;

int add(int a, int b)
{
	total_count++;
	int sumb, suma;
	printf("suma address: %p\n",&suma);
	printf("suma address: %p\n",&suma);
	printf("a address: %p\n",&a);
	printf("b address: %p\n",&b);

	if (a == 0)
	{
		return b;
	}
	else
	{
		sumb = b + 1;
		suma = a - 1;
		return add(suma,sumb);
	}
}

void main()
{
	int result;
	result = add(3,4);
	printf("result: %p\n",%result);
	printf("result_address: %p\n",%result);	
	printf("total_count address: %p\n",%total_count);
	printf("total_sum address: %p\n",%total_sum);
}