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


unsigned long solve2() {
	unsigned long sum = 2;
	for(int i = 3; i < 2000000; i=i+2) {
		if(is_prime(i)) {
			sum = sum + i;
		}
	}
	return sum;


}

int main(void) {
	// takes about 2.155 s
	printf("Ans: %ld\n", solve1());
	// takes about 2.128 s
	printf("Ans: %lu\n", solve2());
	return 0;
}



