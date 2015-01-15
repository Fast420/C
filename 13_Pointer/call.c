// Yunen He 2014
#include<stdio.h>
void inc_count(int *count_ptr)
{
	// (*count_ptr)++;
	*count_ptr += 1;
	printf("%d\n",*count_ptr);
}

int main()
{
	int count = 0;

	while(count < 10)
		// address of & given a thing, point to it
		inc_count(&count);

	const int result = 5;
	// This tells C that the date ponited to by
	// answer_ptr is a constant
	// The data can not be changed
	const char *answer_ptr = "A";


	char letter = "C";
	char *const name_ptr = "B";
	// error: read-only variable is not assignable
	// name_ptr = &letter;
	printf("const pointer %c\n",*name_ptr);
	return 0;
}