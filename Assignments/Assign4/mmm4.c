#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SZ 100000

typedef struct MMM {
  int min;
  int max;
  double mean;
} mmm_t;

static void mmm4(int *array, int size, mmm_t *mmm) {
    // TBD
    int i;
    double sum=0;
    mmm->min=array[0];
    for(i=0;i<size;i++)
    {
        if(array[i]<mmm->min)
        {
            mmm->min=array[i];
        }
        if(array[i]>mmm->max)
        {
            mmm->max=array[i];
        }
        
        sum+=array[i];
    }
    mmm->mean=sum/size;
}

int main(int argc, char *argv[])
{
  int data[SZ];
  int i;
  mmm_t mmm;
  for (i = 0; i < SZ; i++) data[i] = i % 100 + 100;
  mmm4(data, SZ, &mmm);
  printf("Min=%d Max=%d Mean=%.2f\n", mmm.min, mmm.max, mmm.mean);
  return 0;
}
