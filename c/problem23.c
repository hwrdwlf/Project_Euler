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
 * Compile flags: gcc -o problem23 problem23.c -std=c99 -lm
 */


int* prime_factors(int n);
void primeFactors(int n);
int* get_abundant_nums(int n);
int* get_sum_abun_nums(int* array);

int main(void) {
	int n = 28123;
	int* array = get_abundant_nums(n);
	//array[0] = n;

	int* xp = (int*) calloc(n, 4);
	/* Store size in 0 index */
	
	int max = n;
	int a = 1;
	for(n = 2; n < max; n++) {
		if(array[n] > n) {
			//printf("Value: %d\n", n);
			xp[a++] = n;
		}
	}
	/* Done using array, free memory */
	free(array);
	xp[0] = a;
	
	int* sum_two_ab_nums_array = get_sum_abun_nums(xp);
	int size = sum_two_ab_nums_array[0];

	int iter,b;
	int sum = 0;

	// for(b=0; b <= size; b++) {
	// 	if(b== 0) {
	// 		printf("Array size %d\n", sum_two_ab_nums_array[b]);
	// 		continue;
	// 	}
	// 	printf("Num: %d\n", sum_two_ab_nums_array[b]);
	// }
	iter = 1;
	for(b=1; b <= max; b++) {
		//printf("testing %d\n",b);
		if(sum_two_ab_nums_array[iter] == b) {
			if(iter != size) {
				//printf("skipping index %d value %d\n", iter,sum_two_ab_nums_array[iter]);
				iter++;
			} 
		} else {
			//printf("adding\n");
			sum = sum + b;
		}
	}
	printf("Sum: %d\n", sum);

	/* Clean up */
	free(sum_two_ab_nums_array);
	free(xp);
	
}

int* get_sum_abun_nums(int* array) {
	int array_size = array[0];
	int* temp = array;
	printf("Found %d ab nums\n", array_size);
	/* Need to loop through array twice, with the second iteration one index infront of the outer */
	int iter=0;
	int* xp = (int*) calloc(array_size, 28123); // this size is arbitrary
	int i;
	for(i = 1; i <= array_size; i++) {
		int j=0;
		//printf("out %d\n", i);
		if(i == array_size) {
			printf("break\n");
			break;
		}
		//printf("Testing num outer: %d\n", array[i]);
		for(j = i + 1; j <= temp[0]; j++) {
			//printf("in %d\n", j);
			//printf("Testing num inner: %d\n", array[j]);
			//printf("Adding %d + %d\n", array[i], temp[j]);
			int index = iter + 1;
			if(array[i] == 0 || temp[j] == 0) {
				//printf("skip\n");
				continue;
			}
			xp[index] = array[i] + temp[j];
			//printf("index %d\n", iter);
			++iter;
		}
		
	}
	xp[0] = iter;

	return xp;
}

int* get_abundant_nums(int n) {
	int i,j;
	int* xp = (int*) calloc(n, 4);

	for (i=2; i<n; i++)
	    for (j=i*2; j<n; j+= i)
	        xp[j] += i;

	return xp;
}


int* prime_factors(int n) {
	int* array = calloc(n, sizeof(int));
	int i = 1;
	while(n % 2 == 0) {
		array[i] = n;
		n = n / 2;
		i++;
	}

	for(int a = 3; a <= sqrt(n); a = a + 2) {
		while(n % a == 0) {
			array[i] = n;
			n = n / a;
			i++;
		}
	}

	if(n > 2) {
		array[i] = n;
	}

	/* Store the size of the array as the first element */
	array[0] = i;
	return array;
}

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%d ", n);
}