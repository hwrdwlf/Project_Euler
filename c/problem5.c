#include <stdio.h>
#include <math.h>

// Problem 5 for Project Euler
// https://projecteuler.net/problem=5
int gcd(int a, int b){
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b){
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

double solve(double n) {
	double floor(double x);
	double i = floor(n/2.0) + 1.0;
	double lm = i + 1.0;
	for(; i < n; i++)
		lm = lcm(i, lm);
	return lm;
}

int main(void) {
	double solve(double n);
	printf("--- %.1f\n", solve(20.0));
	return 0;
}

