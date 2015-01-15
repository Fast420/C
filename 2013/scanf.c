// Yunen He 2014
#include<stdio.h>
#include<stdlib.h>

# define NAMNELEN 100

int main()
{
	char name[NAMNELEN];

	if (scanf("%s",name) > 0)
	{
		printf("Hello %s\n",name);
	}
	else
	{
		printf("error scanning name.\n");
	}
	return 0;
}