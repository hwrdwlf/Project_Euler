#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Problem 10 for Project Euler
// https://projecteuler.net/problem=10

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

unsigned long solve1() {
	unsigned long limit = 2000000;
	// we know 2 and 3 are prime
	unsigned long sum = 5;
	unsigned long n = 5;

	while(n <= limit) {
		if(is_prime(n)) 
			sum = sum + n;
		n = n + 2;
		if(n <= limit && is_prime(n))
			sum = sum + n;
		n = n + 4;
	}

	return sum;
}

// Running into some weird memory issues with this implementation
// Currently doesn't work
unsigned long solve2() {
	unsigned long limit = 2000000;
	unsigned long crosslimit = (unsigned long)sqrt(limit);
	// create an array of false values based on our upper bound
	unsigned long* sieve = (unsigned long*)malloc(limit * sizeof(unsigned long));
	//memset(sieve, 0, sizeof(limit));
	for(int i = 0; i < limit; i++) {
		sieve[i] = 0;
	}
	unsigned long sum = 0;

	unsigned long n,m;
	for(n = 4; n <= limit; n++) {
		if(!sieve[n])
			sieve[n] = 1;
	}
	for(n = 3; n <= crosslimit; n += 2) {
		if(!sieve[n]){
			for(m = n*n; m <= limit; m = 2 *n){
				sieve[m] = 1;
			}
		}
	}
	
	for(n = 2; n <= limit; n++) {
		if(!sieve[n])
			sum = sum + n;
	}
	free(sieve);
	return sum;
}


int main(void) {
	printf("Ans: %ld\n", solve1());
	//printf("Ans: %lu\n", solve2());
	return 0;
}



