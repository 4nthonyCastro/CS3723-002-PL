#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SZ 100000

static int min;
static int max;
static double mean;

static void mmm2(int *array, int size) {
  min = INT_MAX;
  max = INT_MIN;
  double sum = 0;
  int i;
  for (i = 0; i < size; i++) {
    // TBD
    // ** CHANGES MADE ** //
    if(array[i]<min)
    {
        min=array[i];
    }
    if(array[i]>max)
    {
        max=array[i];
    }
      
    sum+=array[i];
  }
  mean = sum / size;
}

int main(int argc, char *argv[]) {
  int data[SZ];
  int i;
  for (i = 0; i < SZ; i++) data[i] = i % 100 + 100;
  mmm2(data, SZ);
  printf("Min=%d Max=%d Mean=%.2f\n", min, max, mean);
  return 0;
}
