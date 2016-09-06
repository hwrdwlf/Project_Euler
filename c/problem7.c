#include <stdio.h>
#include <math.h>

// Problem 7 for Project Euler
// https://projecteuler.net/problem=7

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

int solve() {
	int i = 0;
	int n = 1;
	do {
		n++;
		if(is_prime(n))
			i++;
	} while(i != 10001);

	return n;
}

int main(void) {
	printf("Ans: %d\n", solve());
	return 0;
}



