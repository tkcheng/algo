/*
 *  This code perform QuickSort Algorithm
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #include "benchmark_timer.h" */
/* #define PRINT_SORTED_RESULT */

#define RANDOM_SIZE		32		//make it memory align
int RandomValue[RANDOM_SIZE] = {
		12, 87, 45, 76, 23, 12, 34, 98, 84, 93,
		96, 61, 15, 20, 74, 62, 13, 50, 29, 34,
		84, 27, 93, 10, 54, 22, 98, 25, 47, 12,
		35, 87
};
int Array[33*1024];

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
        printf("in for loop\n");
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

int main(void)
{
  int j;
  int i, size=sizeof(Array)/sizeof(int), random_size = sizeof(RandomValue);
  int ArraySize = sizeof(Array);
  double duration;
  /* struct high_resolution_timer timer_a; */

  printf("Array size:%d\n", ArraySize);
  printf("size:%d\n", size);
  printf("random_size:%d\n", random_size);
  printf("RANDOM_SIZE:%d\n", RANDOM_SIZE);
  printf("sizeof(RandomValue):%d\n", sizeof(RandomValue));
  for(i=0;i<ArraySize;i+=random_size)
  {
      if(i>=ArraySize)
          break;
      printf("i:%d\n", i);
      memcpy(&Array[i/4], RandomValue, random_size);
  }

  printf("before QS\n");
  //run quicksort algorithm
  QuickSort(Array, 0, size-1);
  /* duration = timer_a.elapsed(); */
  /* printf("duration:%f:Secs\n", duration); */

#ifdef PRINT_SORTED_RESULT
  //print result
  for(i=0; i<size; i++)
  {
    printf("%d \n", Array[i]);
  }
  printf("\n");
#endif //#ifdef PRINT_SORTED_RESULT

  return 0;
}

