// Yunen He 2014
#include<stdio.h>

void add(int a, int b, int *res)
{
	*res = a + b;
}

int main()
{
	int res;
	add(4,5,&res);
	printf("%d \n",res);
	return 0;
}