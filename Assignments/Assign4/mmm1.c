#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SZ 1000000

static int mmm1a(int *array, int size) {
  int min=INT_MAX;
  int i;
  for (i=0;i<size;i++)
  {
    // TBD
    if(array[i]<min)
    {
        min=array[i];
    }
    //min = array[i];
  }
  return min;
}

static int mmm1b(int *array, int size) {
  int max=INT_MIN;
  int i;
  for (i=0;i<size;i++)
  {
      //TBD
      if(array[i]>max)
      {
        max=array[i];
      }
  }
  return max;
}

static double mmm1c(int *array, int size) {
  double sum=0;
  int i;
  for (i=0;i<size;i++){
    // TBD
        sum+=array[i];
  }
  return sum/size; //TBD
}

int main(int argc, char *argv[]) {
  int data[SZ];
  int i;
  for (i=0;i<SZ;i++) data[i] = i % 100 + 100;
  int min = mmm1a(data, SZ);
  int max = mmm1b(data, SZ);
  double mean = mmm1c(data, SZ);
  printf("Min=%d Max=%d Mean=%.2f\n", min, max, mean);
  return 0;
}
