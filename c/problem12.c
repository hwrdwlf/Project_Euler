#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Problem 12 for Project Euler
// https://projecteuler.net/problem=12
#define MAX 500
#define PRIMEBOUND 65500

int is_prime(int num) {
	if(num <= 1) 
		return 0;
	int i;
	for(i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) {
			break;
		}
	}

	if(i > sqrt(num))
		return 1;

	return 0;
}

// Previous version took pretty much forever
// Calculating primes before hand solves this in about 0.028s
int main(void) {
	int triangle = 1;
	int a = 1;
	int count = 0;
	int tt, i, exp;
	int primes[PRIMEBOUND];

	int x = 0;
	for(int i=2; i<PRIMEBOUND;i++) {
		if(is_prime(i)) {
			primes[x++] = i;
		}
	}

	while(count <= 500) {
		count = 1;
		a = a +1;
		triangle = triangle + a;
		tt = triangle;
		for(i = 0; i < PRIMEBOUND; i++) {
			if(primes[i] * primes[i] > tt) {
				count = 2 * count;
				break;
			}

			exp = 1;
			while(tt % primes[i] == 0) {
				exp++;
				tt = tt/primes[i];
			}
			if(exp > 1) {
				count = count * exp;
			}
			if(tt == 1) {
				break;
			}
		}
	}

	printf("Ans: %d\n", triangle);
	return 0;
}



