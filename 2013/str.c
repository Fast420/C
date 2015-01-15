// Yunen He 2014
#include<stdio.h>
#include<string.h>

int main()
{
	char str[30];

	char name[] = "Yunen";

	if (strcmp("Yunen",name) == 0)
		printf("match\n");

	//
	strcpy(str,"Yunen");

	if (strcmp("Yunen",name) == 0)
		printf("match\n");

	// length of string
	int length = 0;
	length = strlen(str);

	printf("length of str: %d\n",length);
}