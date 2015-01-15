// Yunen He 2014
#include<stdio.h>

void fun(int *x)
{
	*x = 200;
}

int main()
{
	int x;
	int w;
	int *p;
	x = 9;
	w = 20;
	p = &x;

	printf("%p\n",p);
	printf("%p\n",&w);
	printf("%d\n",*p);

	x = 5;
	// pass the address of w to the pointer
	p = &w;
	printf("%d\n",*p);

	fun(&w);
	printf("w: %d\n",w);

	return 0;
}