#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>
#include <stdbool.h>

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#define MAX 10000

struct amicable_pairs {
	int a;
	int b;
	int result;
};
struct amicable_pairs amicable_array[MAX];

int amicable(int num);
int amicable_helper(int num, struct amicable_pairs* array);
int main(void) {

	amicable(MAX);
}

int amicable(int num) {
	
	for(int i = 1; i < num; i++) {
		// calculate the amicable pairs for each number
		//printf("Testing %d\n", i);
		amicable_helper(i, &amicable_array[i]);
	}

	int total = 0;
	for(int x = 1; x < num; x++) {
		//printf("Struct[%d]: A-> %d, B-> %d, Result->%s\n", x, amicable_array[x].a, amicable_array[x].b, amicable_array[x].result == 1 ? "true" : "false");
		if(amicable_array[x].result == 1) {
			//total = total + x;
			if(amicable_array[x].a != amicable_array[x].b) {
				printf("Struct[%d]: A-> %d, B-> %d\n", x, amicable_array[x].a, amicable_array[x].b);
				total = total +  x;
			}
			
		}
	}
	printf("Total: %d\n", total);
}

int amicable_helper(int num, struct amicable_pairs* array) {
	// find out if there is an amicable pair for this number
	int a = 0;
	int b = 0;

	for(int i = 1; i < num; i++) {
		//printf("Finding iter %d of d(a)\n", i);
		if(num % i == 0) {
			a = a + i;
		}	
	}

	//printf("d(%d) = %d\n", num, a);

	for(int x = 1; x < a; x++) {
		//printf("Finding iter %d of d(b)\n", x);
		if(a % x == 0) {
			b = b + x;
		}
	}

	//printf("d(%d) = %d\n", a, b);

	if(b == num) {
		array->a = a;
		array->b = b;
		array->result = 1;
	} else {
		array->a = 0;
		array->b = 0;
		array->result = 0;
	}
}
