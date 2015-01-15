// Yunen He 2014
#include<stdio.h>

int main()
{
	int value;
	int sum = 0;

	while(scanf("%d",&value) == 1)
	{
		sum = sum + value;
	}
	printf("sum:%d \n",sum);
	return 0;
}