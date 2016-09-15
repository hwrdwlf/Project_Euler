#include <stdio.h>

// Problem 18 for Project Euler
// https://projecteuler.net/problem=18

int main(void) {
	int height = 15;
	int arraySize = (float)height / 2  * (height + 1);
	int grid[arraySize];
	char buffer[500];
	FILE* fp = fopen("prob18.txt", "r");
	int i = 0;

	while(fgets(buffer, 500, fp) != NULL) {
		int ib = 0;
		while(buffer[ib] != '\0') {
			if(buffer[ib] > 47 && buffer[ib] < 58) {
				grid[i] = (buffer[ib] - 48) * 10 + buffer[ib + 1] - 48;
				i++;
				ib += 2;
			} else {
				ib++;
			}
		}
	}
	fclose(fp);

	int x = arraySize - height * 2 + 1;
	for(int y = height - 1; y > 0; y--) {
		for(int z = 0; z < y; z++) {
			int l = grid[y+x];
			int r = grid[y+x+1];

			if(l > r) {
				grid[x] += l;
			} else {
				grid[x] += r;
			}
			x++;
		}
		x -= y * 2 - 1;
	}
	printf("Ans: %d\n",grid[0]);
	return 0;
}