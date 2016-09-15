#include <stdio.h>
#include <gmp.h>

// Problem 16 for Project Euler
// https://projecteuler.net/problem=16
// Compile Flag; gcc -g -Wall -o problem16 problem16.c -lgmp


int main(void) {
	mpz_t res, number, base;
	unsigned long exp = 1000;
	unsigned long result = 0	;
	mpz_init(base);
    mpz_init(res);
    mpz_init(number);

    mpz_init_set_str(base, "2", 10);

    mpz_pow_ui(number, base, exp);

    while(mpz_sgn(number)) {
    	result += mpz_mod_ui(res, number, 10);
    	mpz_fdiv_q_ui(number, number, 10);

    }

    printf("Ans: %lu\n", result);
	return 0;
}