#include <stdio.h>
#include <math.h>

// Problem 9 for Project Euler
// https://projecteuler.net/problem=9


double solve1() {
	// Adding register double a,b decreases the run time by .003s
	double a=1, b=1;
	while(a + b + sqrt( pow(a,2) + pow(b,2) ) != 1000) {
		a +=1;
		if(a == 998) {
			b+=1;
			a=1;
		}
	}
	return (int) (a * b * sqrt(pow(a, 2) + pow(b, 2)));
}

int main(void) {
	printf("Ans: %.f\n", solve1());
	return 0;
}



