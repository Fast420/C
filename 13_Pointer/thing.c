// Yunen He 2014
#include<stdio.h>

int main()
{
	int thing_var;
	int *thing_ptr;

	thing_var = 2;
	printf("Thing %d\n",thing_var);

	// given a thing,point to it
	// thing_ptr (pointer to an integer)
	thing_ptr = &thing_var;

	// thing_ptr points thing_var
	// thing_var changes to 3
	// *thing_ptr Integer
	*thing_ptr = 3;

	// dereference (given a pointer,get the thing referenced)
	printf("thing_ptr %d\n",*thing_ptr);
	printf("thing_var %d\n",thing_var);

	int sth;

	int *first_ptr;
	int *second_ptr;

	sth = 1;

	first_ptr = &sth;
	second_ptr = first_ptr;

	printf("first_ptr %d\n",*first_ptr);
	printf("second_ptr %d\n",*second_ptr);

	return 0;
}