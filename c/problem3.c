#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

// Problem 3 for Project Euler
// https://projecteuler.net/problem=3
void divisionAns() {
	int64_t number = 317584931803;
	int divisor = 2;

	while (number > 1) {
		if(0 == (number % divisor)) {
			number /= divisor;
			divisor--;
		}
		divisor++;
	}
	printf("Ans: %d\n", divisor);
}

void factors(long long int num)
{
    long long int i;
    long long int n;
    long long int x = 1;
    n = num;
    for(i = 2; i < (sqrt(n)+1); i++)
    {
        while(n % i == 0)
        {
            x = x*i;
            n = n/i;
        }
    }
    printf("Ans: %lld\n",num/x);

}


int main(void) {
	factors(600851475143);
    return 0;
}


