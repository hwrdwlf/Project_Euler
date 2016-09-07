#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Problem 15 for Project Euler
// https://projecteuler.net/problem=15


void count_routes(int m, int n) {
	long grid[m+1][n+1];
	long i,j;

	for(i = 1; i <= m; i++){
		grid[i][0] = 1;
	}

	for(j = 1; j <= n; j++) {
		grid[0][j] = 1;
	}

	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	}

	printf("ans: %ld\n", grid[m][n]);
}

// using combinations this should work but it is not
// outputing the right answer
long super_counter_routes(int n) {
	long result = 1;
	for(long i = 1; i <= n; i++) {
		int calc = (n+i) / i;
		result = result * calc;
	}

	return result;
}

int main(void) {
	count_routes(20,20);
	//printf("Ans: %ld\n", super_counter_routes(20));
	return 0;
}