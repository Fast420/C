// Yunen He 2014

#include <stdio.h>

void sort_array(int array[], int len)
{
    int position,swap;
    position = 0;
    swap = 0;
    
    for (int i = 0 ; i < len - 1; i++ )
   {
      position = i;

      for (int j = i + 1 ; j < len; j++ )
      {
         if (array[position] > array[j] )
            position = j;
      }
      if ( position != i)
      {
         swap = array[i];
         array[i] = array[position];
         array[position] = swap;
      }
   }

   for (int i = 0; i < len; ++i)
   {
    printf("%d ",array[i]);
   }
}


int main() {
    int array[] = {4,7,3,8};

    sort_array(array,4);

    printf("\n");
    return 0;
}