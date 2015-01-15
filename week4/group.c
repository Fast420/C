// Yunen He 2014
/**
implement a program that takes a list of numbers on standard input and finds if any 3 numbers sum to 100.
If there are 3 numbers that sum to 100 then output "yes" otherwise output "no".
**/

#include <stdio.h>
#include <stdlib.h>

int array[10000];
int size = 0;
int sum = 0;
int count = 0;

int finder(int array[])
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (int  k= 0; k < size; ++k)
            {
                sum = array[i] + array[j] + array[k];
                if (sum == 100)
                    return 1;
            }
        }
    }
    return 0;
}

int main() 
{
	// read txt file
	FILE *ptr_file;
    char buffer[1000];

    ptr_file =fopen("test4yes.txt","r");
    if (!ptr_file)
    	return 1;

    while (fgets(buffer,1000, ptr_file)!=NULL)
    {
    	array[size] = atoi (buffer);
    	size++;
    }
    fclose(ptr_file);


    if (finder(array) == 1)
    {
    	printf("yes \n");
    }
    else
    {
    	printf("no \n");
    }

}

