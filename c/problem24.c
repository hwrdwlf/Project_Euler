#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem 24 for Project Euler
// https://projecteuler.net/problem=24

// Permutation algorithm: https://en.wikipedia.org/wiki/Heap%27s_algorithm
// Lexiographic permutations: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 
/** 
 * function is needed for library function qsort().
 * refer to http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ 
 */
int compare (const void *a, const void * b) {  
	return ( *(char *)a - *(char *)b ); 
}
 
void swap (char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}
 
// the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int find_ceil (char str[], char first, int l, int h)
{
    // initialize index of ceiling element
    int ceil_index = l;
 
    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceil_index])
            ceil_index = i;
 
    return ceil_index;
}
 
//  all permutations of str in sorted order
void sorted_permutations ( char str[] )
{

    int size = strlen(str);
 	int done = 0;
    int max = 1;
    
    qsort( str, size, sizeof( str[0] ), compare );

    while ( ! done )
    {
        // print this permutation
        //printf ("[%d]: %s \n", max, str);

        if(max >= 1000000) {
        	// print answer
        	printf("Ans: %s\n", str);
        	break;
        } else {
        	++max;
        }
 
        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for ( i = size - 2; i >= 0; --i )
           if (str[i] < str[i+1])
              break;
 
        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if ( i == -1 )
            done = 1;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceil_index = find_ceil( str, str[i], i + 1, size - 1 );
 
            // Swap first and second characters
            swap( &str[i], &str[ceil_index] );
 
            // Sort the string on right of 'first char'
            qsort( str + i + 1, size - i - 1, sizeof(str[0]), compare );
        }
    }
}
 
// Driver program to test above function
int main()
{
    char str[] = "0123456789";
    sorted_permutations( str );
    return 0;
}
