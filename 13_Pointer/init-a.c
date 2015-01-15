// Yunen He 2014
#include<stdio.h>

#define MAX 10

void init_array_1(int data[])
{
	for (int index = 0; index < MAX; ++index)
		data[index] = 0;
}

void init_array_2(int *data_ptr)
{
	for (int index = 0; index < MAX; ++index)
		*(data_ptr + index) = 0;
}

void copy_str(char *dest, char *source)
{
	while(1)
	{
		*dest = *source;

		if (*dest == '\0')
		{
			return;
		}
		++dest;
		++source;
	}
}

int main()
{
	int array[MAX];

	void init_array_1();
	void init_array_2();
	void copy_str();

	init_array_1(array);

	init_array_2(&array[0]);
	init_array_2(array);

	char *str1 = NULL;
	char *str2 = "Yunen";


	copy_str(&str1,&str2);

	printf("%s\n",str1);

	return 0;
}
