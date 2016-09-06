#include <stdio.h>
#include <math.h>

// Problem 6 for Project Euler
// https://projecteuler.net/problem=6

/*  The sum of squares is n*(n +1)*(2*n +1) /12
    The square of sum of n numbers is  ( n*(n+1)/2 ) * ( n *(n +1)/2 )
    If we take the diffrence and solve it algebraically
    We get the diffrence to be  -> ( 3 * n^4 + 2 * n^3 -3 * n^2 - 2 * n )/12
    so answer is the value of above expression
    

    http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalNumbers.htm
    http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
    http://mathforum.org/library/drmath/view/56920.html
*/
int algSolve() {
	int num = 100;
	long temp = 0;
	int diff;
	temp = num * num;
	diff = ( 3 * temp * temp + 2 * temp * num - 3 * temp - 2 * num ) / 12;
	return diff;
}

double normSolve(int n) {
	double s = 0;
	double i = 0;

	for(i = 1; i <= n; i++) {
		s += i*i;
	}

	return (n*(n+1.0)/2.0) * (n*(n+1.0)/2.0) - s;
}

int main(void) {
	printf("Ans: %d\n", algSolve());
	printf("Ans: %.lf\n", normSolve(100));
	return 0;
}



