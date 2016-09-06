#include <stdio.h>

// Problem 2 for Project Euler
// https://projecteuler.net/problem=2

int main(void) {
	unsigned long int a = 1, b = 2, c = 0, sum = 2;
	while(c < 4000000) {
		c = a + b;
		if(!(c % 2)) {
			sum += c;
		}
		a = b;
		b = c;
	}
    printf("Ans:%ld\n", sum);
    return 0;
}