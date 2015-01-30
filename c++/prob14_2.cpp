#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*****************************************************************************
 * https://projecteuler.net/problem=14                                       *
 *                                                                           *
 * Longest Collatz sequence                                                  *
 * Problem 14                                                                *
 * The following iterative sequence is defined for the set of positive       *
 * integers:                                                                 *
 *                                                                           *
 * n → n/2 (n is even)                                                       *
 * n → 3n + 1 (n is odd)                                                     *
 *                                                                           *
 * Using the rule above and starting with 13, we generate the following      *
 * sequence:                                                                 *
 *                                                                           *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1                                *
 * It can be seen that this sequence (starting at 13 and finishing at 1)     *
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), *
 * it is thought that all starting numbers finish at 1.                      *
 *                                                                           *
 * Which starting number, under one million, produces the longest chain?     *
 *                                                                           *
 * NOTE: Once the chain starts the terms are allowed to go above one million *
 *****************************************************************************/

typedef unsigned long long BIGNUM;

// Calculate Collatz sequence starting with argument number
// and return the length of sequence

BIGNUM collatzLength(BIGNUM startNum)
{
    BIGNUM collatz = startNum;
    BIGNUM length = 0;

    while (collatz > 1) {
	++length;
	if ((collatz % 2) == 0)
	    collatz /= 2;
	else
	    collatz = 3 * collatz + 1;
    }

    return length;
}

int main (int argc, char *argv[])
{
    struct {
	BIGNUM length;
	BIGNUM startNum;
    } longest;

    longest.length = 0;

    for (BIGNUM startNum = 2; startNum < 1000000; ++startNum) {
	unsigned length = collatzLength(startNum);
	if (length > longest.length) {
	    longest.length = length;
	    longest.startNum = startNum;
	}
    }

    cout << longest.startNum << endl;

    return 0;
}