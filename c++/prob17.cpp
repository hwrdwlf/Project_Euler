#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <utility>
#include <cmath>


std::vector<char> number_to_word(int num) {
	const char * const ones[20] = {"one", "two", "three","four","five","six","seven",
    "eight","nine","", "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"};
    const char * const tens[10] = {"zero", "ten", "twenty", "thirty","forty","fifty","sixty","seventy",
    "eighty","ninety"};

    std::vector<char> temp;

    if(num < 0) {
    	return temp;
    } else if(num == 1000) { 	
    	std::string str = "one thousand";
    	std::copy(str.begin(), str.end(), back_inserter(temp));
    } else if(num >= 20){
        std::string str(tens[2]);
		std::copy(str.begin(), str.end(), back_inserter(temp));
    } else {
    	if(num == 10) {
    		std::string str(tens[1]);
    		std::copy(str.begin(), str.end(), back_inserter(temp));
    	} else {
    		std::string str(ones[num]);
    		std::copy(str.begin(), str.end(), back_inserter(temp));
    	}
    	
    }

    return temp;

}


int main(){

	for(int i=1; i<21; i++) {
		std::vector<char>result = number_to_word(i);

	    for(std::vector<char>::iterator it = result.begin(); it != result.end(); ++it) {
	    	std::cout << *it;
	    }
	    std::cout<<std::endl;
	}
	

	return 0;
}