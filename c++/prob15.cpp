#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <utility>
#include <cmath>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


unsigned long long  choose(unsigned long long  n, unsigned long long  k){
	 unsigned long long res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if ( k > n - k ) {
    	k = n - k;
    }
        
 
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (unsigned long long i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
    

int main()
{
	unsigned long long  n = 40;
	unsigned long long  k = 20;

	std::cout<< "Number of paths: " << choose(n,k) << std::endl;	
	return 0;
}