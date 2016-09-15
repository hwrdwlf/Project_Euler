#include <stdio.h>

// Problem 19 for Project Euler
// https://projecteuler.net/problem=19

int main(void) {
	int count = 0;
	int day = (1 + 365) % 7;
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	// for all the years
	for(int year = 1; year <= 100; year++) {
		for(int m = 0; m < 12; m++) {
			// If Sunday
			if( day == 0 ) {
				++count;
			}

			// skip february
			if(m != 1) {
				day = (day + months[m]) % 7;
			} else if( year % 4 == 0) {
				// calculate leap years
				day = ( day + 29 ) % 7;
			} else {
				// regular february; ie 28 days
				day = ( day + 28 ) % 7;
			}
		}
	}

	printf("Ans: %d\n", count);

	return 0;
}