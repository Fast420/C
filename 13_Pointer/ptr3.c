// Yunen He 2014
#include <stdio.h>

int array[] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int *array_ptr;

int main()
{
	// array_ptr = &array[0];
    array_ptr = array;

    // dereference operator (*)
    // examine the date in the array
    while ((*array_ptr) != 0)
        ++array_ptr;

    // array_ptr - array, computes how far array_ptr is into the array.
    printf("Number of elements before zero %d\n",array_ptr - array);
    return (0);
}