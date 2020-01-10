/*
 *  This code perform QuickSort Algorithm
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* #define PRINT_SORTED_RESULT */

int Array[100*1024] = { 2, 6, 3, 8, 5, 4, 1, 9, 7 };

void QuickSort(int *target, int left, int right) 
{
    int i,j;
    int tmp, pivot;
    static int recursive_deep_level = 0;
    static int recursive_max_level = 0;

    if(left >= right) 
    {
        return;
    }
    
    i = left;
    j = right;
    pivot = target[i];
    recursive_deep_level++;
    if(recursive_deep_level>recursive_max_level)
    {
        recursive_max_level = recursive_deep_level;
        printf("Max Recursive Level=%d\n", recursive_max_level);
    }

    for(;;) {
        //shift cursor finding target element to shift
        while(target[i] < pivot)
        { 
            i++;
        }
        while(pivot < target[j])
        {
            j--;
        }
        //abort current check when cursor is overlapping
        if(i >= j)
        {
            break;
        }
        //element swap
        tmp = target[i]; 
        target[i] = target[j]; 
        target[j] = tmp;
        //move next 
        i++; j--;
    }
    QuickSort(target, left, i-1);
    QuickSort(target, j+1, right);

    recursive_deep_level--;
}

void main(void)
{
  int i, size=sizeof(Array)/sizeof(int);

  for(i=0;i<size;i++)
  {
      Array[i] = random();
  }

  //run quicksort algorithm
  QuickSort(Array, 0, size-1);

#ifdef PRINT_SORTED_RESULT
  //print result
  for(i=0; i<size; i++)
  {
    printf("%d \n", Array[i]);
  }
  printf("\n");
#endif //#ifdef PRINT_SORTED_RESULT

}

