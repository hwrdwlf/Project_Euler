#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000
#define STRLEN 10

// 1: https://www.cs.princeton.edu/~rs/talks/perms.pdf
// 2: http://arxiv.org/vc/cs/papers/0306/0306025v1.pdf
// 3: Permutation algorithm: https://en.wikipedia.org/wiki/Heap%27s_algorithm

void swap(char* str, int a, int b) {
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}

int get_permutation(char* str, int len) {
	int fkey = len - 1;
	int nkey = len - 1;

	while( (fkey > 0) && ( str[fkey] <= str[fkey-1] ) ) {
		fkey--;
	}

	fkey--;

	if(fkey < 0) {
		return 0;
	}

	while( (nkey > fkey) && ( str[nkey] <= str[fkey] ) ) {
		nkey--;
	}

	swap(str, fkey, nkey);
	len--;
	fkey++;

	while(len > fkey) {
		swap(str, len, fkey);
		fkey++;
		len--;
	}

	return 1;
}

int main(void) {
	char str[] = "0123456789";
	long count = 0;
	do{
		count++;
		if(count == MAX)
			break;
	} while(get_permutation(str, STRLEN));

	printf("Ans: %s\n", str);

	return 0;
}