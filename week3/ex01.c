// Yunen He 2014
#include<stdio.h>
// static int count
int i;
int add(int a, int b)
{
	// static int x = b
	// x is not static, it is used in the following loop.
	int x = b;

	printf("a address: %p\n",&a);
	printf("b address: %p\n",&b);

	for (i = 0; i < a; i++)
	{
		x = x + 1;
		printf("x address: %p\n",&x);
	}
	printf("x address: %p\n",&x);
	return x;
}

int main()
{
	int y;
	y = add(6,8);
	printf("%d\n",y);
	printf("y address: %p\n",y);
}
