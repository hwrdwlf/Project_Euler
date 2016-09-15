#include <stdio.h>
#include <math.h>
// Problem 21 for Project Euler
// https://projecteuler.net/problem=21

#define MAX 9999

int sum_of_divsors( int n ) {
	int sum = 1;
	int p = 2;

	// Don't check prime factors great than sqrt(n)
	while( p*p <= n && n > 1 ) {
		if( n % p == 0) {
			int j = p * p;
			n = n / p;
			while( n % p == 0) {
				j = j * p;
				n = n / p;
			}

			sum = sum * ( j -1 );
			sum = sum / ( p - 1 );
		}
		if( p == 2) {
			p = 3;
		} else {
			p = p + 2;
		}
	}

	// If a prime factor greater than sqrt(n) remains
	if( n > 1 ) {
		sum = sum * ( n + 1 );
	}

	return sum;
}

// For more info: http://mathschallenge.net/index.php?section=faq&ref=number/sum_of_divisors
int sum_of_proper_divsors(int n ) {
	return (sum_of_divsors(n) - n);
}

int main() {
	int sum = 0;
	for(int a = 2; a <= MAX; ++a) {
		int b = sum_of_proper_divsors(a);
		if( b > a ) {
			if( sum_of_proper_divsors(b) == a) {
				sum = sum + a + b;
			}
		}
	}

	printf("Ans:%d\n", sum);
}
