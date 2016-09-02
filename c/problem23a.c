#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 
28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, 
it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. 
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant 
numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/
/* 
 * Compile flags: gcc -o problem23a problem23a.c -std=c99 -lm
 * valgrind: valgrind --leak-check=yes --track-origins=yes ./problem23a 28123
 * run: ./problem23a 28123
 */
int sum_divs[32768];
int summable[32768];
int abundants[32768];
int main(int argc, char *argv[]) {
  const int limit = (argc != 2) ? 12 : atoi(argv[1]);
  const int halflimit = limit / 2;
  // Step one: compute sum of divisors, minus one
  for (int i = 2; i <= halflimit; ++i) {
    for (int j = i + i; j <= limit; j += i) {
      sum_divs[j] += i;
    }
  }
  // Step two: compute a list of all abundant numbers
  int *afiller = &abundants[0];
  for (int n = 2; n <= limit; ++n) {
    if (sum_divs[n] + 1 > n) {
      *afiller++ = n;
    }
  }
  // Step 3: compute the summable numbers
  for (int *a = &abundants[0]; ; ++a) {
    int ab1 = *a;
    if (ab1 > halflimit) break;
    for (int *b = a; ; ++b) {
      int sum = ab1 + *b;
      if (sum > limit) break;
      summable[sum] = 1;
    }
  }
  int sum = 0;
  for (int i = 1; i <= limit; ++i) {
    if (summable[i] != 1) {
      sum += i;
    }
  }
  printf("Sum of unsummables is %d\n", sum);
}