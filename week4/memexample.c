// Yunen He 2014
#include<stdio.h>
#include<stdlib.h>
#define MEMSIZE 10000L

int main()
{
	long i,j,sum;
	long *data;
	data = (long *) malloc(MEMSIZE * sizeof(long));
	if (data == 0)
	{
		printf("unable to malloc\n");
	}
	return 1;

	for ( j = 0; j < 10; j++)
	{
		for (i = 0; i < MEMSIZE; i++)
		{
			data[i] = i;
		}
		for (i = 0; i < MEMSIZE; i++)
		{
			sum += data[i];
		}
	}
	printf("sum %ld\n",sum);
	free(data);
	return 0;
}