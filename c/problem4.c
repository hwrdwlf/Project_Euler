#include <stdio.h>

// Problem 4 for Project Euler
// https://projecteuler.net/problem=4

int palindrome(long int n) {
	long int n1, reverse = 0, digit;
	n1 = n;
	while (n > 0) {
		digit = n % 10;
		reverse = reverse * 10 + digit;
		n /= 10;
	}
	if (reverse == n1)
		return (1);
	else
		return (0);
}

int main(void) {
	long int number, max = 0;
	int i, j;
	for (i = 999; i>100; i--) {
		for (j = i; j>100; j--) {
			number = j*i;
			if (palindrome(number)) {		
				if (max < number)
					max = number;
			}
		}
	}
	printf("Ans: %ld\n", max);
	return 0;
}