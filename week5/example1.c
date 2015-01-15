// Yunen He 2014
#include<stdio.h>

void addto(int *sum, int x)
{
	*sum += x;
}

main()
{
	int x, sum;
	sum = 0;
	while(scanf("%d,&x") == 1)
	{
		addto(&sum,x);
	}
	printf("Sum = %d",sum);
}