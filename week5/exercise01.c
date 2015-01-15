// Yunen He 2014
// Add some code between the show methods such that the list will be shown
// in sorted order without moving the integers in the "array"
// (this involves modifying the "parray" such that it points to the elements of "array" in sorted order).

#include<stdio.h>
#define SIZE 4
void show(int *pa[], int len) {
	int i;
	for (i=0;i<len;i++) printf("%d ", *pa[i]);
	printf(" ");
}

// selection sort
void sort_array(int *array[], int len)
{
	int position,*swap;
    position = 0;

    for (int i = 0 ; i < len - 1; i++ )
   {
      position = i;

      for (int j = i + 1 ; j < len; j++ )
      {
      	// comapre two poniters
         if (*array[position] > *array[j])
            position = j;
      }
      if (position != i)
      {
         swap = array[i];
         array[i] = array[position];
         array[position] = swap;
      }
   }
}

int main() {
	int array[] = {4,7,3,8};
	int *parray[SIZE];
	int i;
	for (i=0;i<SIZE;i++) parray[i] = &array[i];
	show(parray,4);
	printf("\n");
	// add your code here
	sort_array(parray,SIZE);

	printf("sorted: \n");
	show(parray,SIZE);
	printf("\n");
	return 0;
}