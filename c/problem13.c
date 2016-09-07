#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Problem 13 for Project Euler
// https://projecteuler.net/problem=13

int main(void)
{
	char list[100][50];
	FILE *fp = fopen("number.txt", "r");
	int i = 0, k, temp = 0, num;

	if (fp == NULL){
		printf("Failed to open file\n");
		exit(1);
	}

	while (fscanf(fp, "%s", &list[i]) != EOF)
		i++;

	for (k = 49; k >= 0; k--)
	{
		num = 0;
		for (i = 0; i<=99 ; i++)
			num += (list[i][k]-'0');
		temp += num;
		printf("%d\n", temp % 10);
		if (temp != 0)
			temp /= 10;
	}
	fclose(fp);
	printf("Ans: %d\n", temp);

	return 0;
}