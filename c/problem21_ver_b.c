#include <stdio.h>

int d( int n ) {
	int tsum = 0 , i;
	for( i = n / 2 ; i > 0 ; i-- )
		tsum += (n % i)? 0 : i;
	return tsum;
}

int main() {
	long int sum1 = 0 , sum2 = 0;
	int x = 0 , y = 0;
	for( x = 1 ; x < 10000 ; x++ ) {
		y = d( x );
		if( d( y ) == x && y != x )
			sum1 += x;
	}
	printf( "%ld\n" , sum1 ); 
}
