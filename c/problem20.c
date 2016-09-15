#include <gmp.h>
#include <stdio.h>

// Problem 20 for Project Euler
// https://projecteuler.net/problem=20

int main(void) {

	mpz_t res,nm;
	mpz_init(res);
	mpz_init(nm);
	
	mpz_set_ui(res, 1);
	unsigned long i;
	
	for (i = 2 ; i <= 100; i++){
		mpz_mul_ui(res, res,i);
	}

	
	
	i = 0;
	mpz_set(nm,res);
	while (mpz_sgn(nm)) {
		i += mpz_mod_ui(res, nm , 10);
		mpz_fdiv_q_ui(nm , nm , 10);
	}	


	printf("%lu\n" , i);

	return 0;
}