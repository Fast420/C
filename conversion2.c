#include<stdio.h>
#include<stdlib.h>

// Author
// Yunen He
// ZeFeng Ding

// convert the number in the lower base into the number in the higher base
// by default, base is 2
int
main()
{
	int a[100];
	int value,size;
	int base,accum,sum;

	scanf("%d",&value);
	size = 0;
	base = 2;
	sum = 0;
	while(value != 0)
	{
		a[size] = value % 10;
		value = value / 10;
		size++;
	}

	for (int i = 0; i < size; i++)
	{
			accum = base;
			if (i == 0)
			{
				accum = 1;
			}
			else
			{
				for (int power = 0; power < i-1; power++)
				{
					accum = accum * base;
				}
			}
			a[i] = a[i] * accum;
			sum = sum + a[i];
	}
	printf("%d\n",sum);
}