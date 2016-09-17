#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Problem 14 for Project Euler
// https://projecteuler.net/problem=14
#define MAX 1000000
#define ui unsigned int 

void solve1() {
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
}


void solve2() {
	ui no = 3;
	ui lc = 0;
	ui ln = 0;
	ui limit = 1000000;

	while(no < limit) {
		ui c = no;
		ui steps = 1;

		while(c != 1) {
			if(c % 2 == 0) {
				c /= 2;
				steps++;
			} else {
				c = (c * 3 + 1) / 2;
				steps += 2;
			}
		}

		if(lc < steps) {
			lc = steps;
			ln = no;
		}
		no++;
	}

	printf("Ans: %d\n", ln);
}

void solve3() {
	ui sn = 0;
	ui ls = 0;
	ui limit = 1000000;
	ui* nums = (ui*)malloc(limit * sizeof(ui));
	memset(nums, 0, limit * sizeof(ui));

	for(ui i = limit / 2 + 1; i < limit; i += 2) {
		ui len = 0;
		ui x = i;

		while( x != 1 ) {
			len++;
			x = x % 2 ? x * 3 + 1 : x / 2;

			if(x < i) {
				len += nums[x];
				break;
			}
		}
		nums[i] = len;

		if(ls < len) {
			ls = len;
			sn = i;
		}
	}

	printf("Ans: %d\n", sn);

	free(nums);
}



int main(void) {
	clock_t begin = clock();
	solve1();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Computation time %f\n", time_spent);

	begin = clock();
	solve2();
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Computation time %f\n", time_spent);

	begin = clock();
	solve3();
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Computation time %f\n", time_spent);

	return 0;
}