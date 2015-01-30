#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[] )
{
  int j,k,l;
  long long sum = 2;
  int nrs[(int)2E6];
  clock_t t;
  t = clock();
  // Filling array
  for(j = 3; j < 2E6; j+=2) {
    nrs[j] = j;
  }
  //printf("Starting prime calculation...\n");
  for( j = 3; j < 2E6; j+=2 ) {
    if( nrs[j] != 0 ) {
      for(k = j+j; k < 2E6; k = k + j ) {
        nrs[k] = 0;
      }
    }
  }
  //printf(" ...done.\n");
  for(j = 3; j < 2E6; j+=2) {
    if( nrs[j] != 0 ) {
      sum += nrs[j];
      //printf("%i\n", nrs[j]);
    }
  }
  t = clock() - t;
  printf("sum=%lli in t=%f s\n",sum, ((float)t)/CLOCKS_PER_SEC );
}



