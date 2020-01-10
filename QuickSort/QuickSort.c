/*
 *  This code perform QuickSort Algorithm
 *
 */

#include <stdio.h>
#include <stdlib.h>

int Array[100*1024] = { 2, 6, 3, 8, 5, 4, 1, 9, 7 };

void QuickSort(int *target, int left, int right) 
{
    int i,j;
    int tmp, pivot;

    if(left >= right) 
    {
        return;
    }
    
    i = left;
    j = right;
    pivot = target[i];

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

  //print result
  for(i=0; i<size; i++)
  {
    printf("%d \n", Array[i]);
  }
  printf("\n");
}

