#include<stdio.h>
#include<stdlib.h>

#define NAMELEN 100

int
main()
{
	char name[NAMELEN];

	if (scanf("%s",name) > 0)
	{
		printf("Hello %s\n", name);
	}
	else
	{
		printf("error scanning name.");
	}
}