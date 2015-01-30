#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <utility>


unsigned long find_max_collatz(unsigned long max) {
	unsigned long length = 0;
	while (max > 1) {
		++length;
		if((max%2==0)) {
			max = max / 2;
		} else {
			max = max * 3 + 1;
		}
	}

	return length;
}


int main()
{
	struct {
		unsigned long length;
		unsigned long startNum;
    } collatz;

    unsigned long MAX_NUM = 1000000;

    for(unsigned long x = 0; x < MAX_NUM; x++) {
    	unsigned long length = find_max_collatz(x);
    	if (length > collatz.length) {
	    	collatz.length = length;
	    	collatz.startNum = x;
		}

    } 

    std::cout << collatz.startNum << std::endl;

	return 0;
}