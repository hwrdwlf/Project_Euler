#include <stdio.h>

// Problem 20 for Project Euler
// https://projecteuler.net/problem=20

#define MAX 28123

int is_abundant(int j) {
     int divisors = 0;
     for (int n = 2; n * n <= j; n++) {
         if (!(j % n)) {
            divisors += n;
            if (n < j / n)
               divisors += j / n;
            if (j <= divisors)
               return 1;
         }
     }
     return j <= divisors;
}

int main(void) {
    int abundant[MAX];
    int checked[MAX];               
    int count = 0, total = 0;
    for (int n = 1; n < MAX; n++) {
        if (is_abundant(n))
           abundant[count++] = n;   
    }

    for (int a = 0; a < count; a++) {
        for (int b = a; b < count; b++)
            if (abundant[a] + abundant[b] < MAX)
                checked[abundant[a] + abundant[b]] = 1;
    }

    for (int n = 1; n < MAX; n++) {
        if (!checked[n])
            total += n;
    }
    
    printf("%d\n", total);

    return 0;
}