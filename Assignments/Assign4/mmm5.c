#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SZ 100000

typedef struct MMM {
  int min;
  int max;
  double mean;
} mmm_t;

static mmm_t *mmm5(int *array, int size) {
  mmm_t *mmm = (mmm_t *) malloc(sizeof(mmm_t));
    // TBD
    // ** CHANGES MADE ** //
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
    return mmm;
}

int main(int argc, char *argv[]) {
  int data[SZ];
  int i;
  for (i = 0; i < SZ; i++) data[i] = i % 100 + 100;
  mmm_t *mmm = mmm5(data, SZ);
  printf("Min=%d Max=%d Mean=%.2f\n", mmm->min, mmm->max, mmm->mean);
  return 0;
}
