#include <stdio.h>
#include <stdlib.h>
#include "glib.h"
FILE *file;

typedef struct
{
   int *array;
   size_t used;
   size_t size;
}Array;

void initArray( Array *a, size_t initSize )
{
   a->array = (int *)malloc(initSize * sizeof( int ));
   a->used  = 0;
   a->size  = initSize;
}
void insertArray( Array *a, int element )
{
   if( a->used == a->size )
   {
      a->size *= 2;
      a->array = (int *)realloc(a->array, a->size * sizeof( int ));
   }
   a->array[a->used++] = element;
}
void freeArray( Array *a )
{
   free( a->array );
   a->array = NULL;
   a->used = a->size = 0;
}

void readFile( char *file_name )
{
    int c;
    file = fopen(file_name, "r");

    if (file == NULL)
        fprintf( stderr, "Could not open file.\n" ); //could not open file
        exit( 1 );

    while((c = fgetc(file)) != EOF)
    {
    }

    // don't forget to terminate with the null character

}

int main()
{
   char *i;
   file = fopen("problem11data.txt", "r");
   if(file == NULL)
   {
      fprintf(stderr, "Could not open file.\n");
      exit(1);
   }

   i = fgetc(file);
   printf("Current val: %s\n", i);
   fclose(file);
   exit( EXIT_SUCCESS );

}
