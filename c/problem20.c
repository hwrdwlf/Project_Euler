#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>



void fact(mpz_t result, int n);
char * convertNumberIntoArray(long number);
char* convert_num_to_array(mpz_t num);

int main(void) {
	mpz_t result, ans;
	mpz_init_set_ui(result,1);

	fact(result ,100);
	gmp_printf("ans: %Zd\n", result);

	mpz_set(ans,result);
	unsigned long i;
	while (mpz_sgn(ans)) {
		i += mpz_mod_ui(result, ans , 10);
		mpz_fdiv_q_ui(ans , ans , 10);
	}	

	printf("Ans: %lu\n", i);

	mpz_clear(result);
	return 0;

}

void fact(mpz_t result, int n){
  int i;
  for (i=1; i <= n ; ++i){
    mpz_mul_ui(result,result,i); /* r = r * i */
  }
 
}

char* convert_num_to_array(mpz_t num) {

}

char* convertNumberIntoArray(long number) {
    unsigned long length = (long)(log10((float)number)) + 1;
    char* arr = (char *) malloc(length * sizeof(char)), *curr = arr;
    do {
    	*curr++ = number % 10;
    	number /= 10;
    } while (number != 0);
    return arr;
}