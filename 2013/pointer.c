// Yunen He 2014
#include<stdio.h>

int main()
{
	int val = 0;
	int *pointer;

	pointer = &val;

	*pointer = 7;

	printf("val %d\n",val);
	printf("ptr %d\n",*pointer);


	// array
	int array[] = {7,4,2,6};
	int *ptr;

	// ptr = &array[0];
	ptr = array;

	printf("%d\n",*ptr);

	// increase the pointer
	ptr += 2;

	printf("%d\n",*ptr);
}