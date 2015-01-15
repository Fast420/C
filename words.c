// Yunen He 2014
#include<stdio.h>

struct data
{
	int x;
	int y;
	char c1;
};

void
main()
{
	printf("%ld\n",sizeof(struct data));
}