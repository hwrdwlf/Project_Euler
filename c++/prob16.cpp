#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <utility>
#include <cmath>


int pow_to_sum() {
	int list[1000];

	for(int i=0; i<1000; i++) {
		list[i] = 0;
	}

	list[0] = 1;
	for(int j=0; j<1000; j++) {
		int carry, add = 0;
		for(int x=0; x<1000; x++) {
			int prod = list[x] * 2 + carry;
			if(prod > 9) {
				carry = 1;
				prod = prod % 10;
			} else {
				carry = 0;
			}
			list[x] = prod;
		}
	}

	int total = 0;
	int sizeOf = sizeof(list) / sizeof(list[0]);
	std::cout << "size of array: " << sizeOf << std::endl;
	for(int a=0; a < sizeOf; a++) {
		total += list[a];
	}
	return total;
}

int main(){

	int result = pow_to_sum();
	std::cout << "result: " << result << std::endl;


	return 0;
}