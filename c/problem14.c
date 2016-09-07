#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Problem 14 for Project Euler
// https://projecteuler.net/problem=14
#define MAX 1000000

int main(void) {
	int longest = 0;
	int terms = 0;
	int i;
	unsigned long j;

	for(i = 1; i < MAX; i++) {
		j = i;
		int c = 1;

		while(j != 1) {
			if(j % 2 == 0) {
				j /= 2;
			} else {
				j = 3 * j + 1;
			}
			c++;
		}

		if(c > terms) {
			terms = c;
			longest = i;
		}
	}
	printf("longest: %d (%d)\n", longest, terms);
	return 0;
}