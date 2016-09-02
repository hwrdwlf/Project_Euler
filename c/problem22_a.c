#include <stdio.h>

#define BUF_LENGTH 50

int value( char *name ) {
    int sum = 0;
    for (int i = 0; name[ i ] > 0; ++i) {
        sum += name[ i ] - 'A' + 1;
    }
    return sum;
}

int main() {
    int sum = 0, row = 1;
    char buf[ BUF_LENGTH ];
    while (gets( buf ) != NULL) {
        sum += row * value( buf );
        ++row;
    }
    printf( "%d\n", sum );
    return 0;
}