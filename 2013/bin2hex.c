// Yunen He 2014
#include<stdio.h>

char convertAF(int num)
{
	if (num == 10)
	{
		return 'A';
	}

	if (num == 11)
	{
		return 'B';
	}

	if (num == 12)
	{
		return 'C';
	}

	if (num == 13)
	{
		return 'D';
	}

	if (num == 14)
	{
		return 'E';
	}

	if (num == 15)
	{
		return 'F';
	}

	return 0;
}

int main()
{
	long int a[16];
	long int tmp[16];
	long int weighting[4];
	long int num = 0;
	int size = 0;
	int i = 0;
	int print_zero = 0;
	int num_copy = 0;

	//
	weighting[0] = 8;
	weighting[1] = 4;
	weighting[2] = 2;
	weighting[3] = 1;

	// main code goes here
	scanf("%ld",&num);
	num_copy = num;

	// split num into digits
	while(num != 0)
	{
		tmp[size] = num % 10;
		num = num / 10;
		size++;
	}

	// reverse
	int count = 15;
	for (i = 0; i < size; i++)
	{
		a[count] = tmp[i];
		count--;
	}

	// formatting
	for (i = 0; i < count; i++)
	{
		a[i] = 0;
	}

	printf("%s","0X");

	//
	int result = 0;
	for (i = 0; i < 16; i++)
	{
		if ((i + 1) % 4 == 0)
		{
			result = (weighting[0] * a[i - 3]) + (weighting[1] * a[i - 2]) + (weighting[2] * a[i - 1]) + (weighting[3] * a[i]);
			//
			if (result > 9)
			{
				printf("%c",convertAF(result));
				print_zero = 1;
			}
			else
			{
				if (result == 0)
				{
					if (print_zero == 1)
					{
						printf("%d",result);
					}
				}
				else
				{
					printf("%d",result);
					print_zero = 1;
				}
			}
		}
	}

	// a special case
	if (num_copy == 0)
	{
		printf("%d",0);
	}

	printf("\n");
}