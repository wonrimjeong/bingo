#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print_bingo.h"


void print_bingo(int(*p)[N])
{
   int i, j;

   for (i = 0; i < N; i++)
   {
      	for (j = 0; j < N; j++)
			printf("%3d", p[i][j]);
      		printf("\n");
   }
}
