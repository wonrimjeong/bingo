#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

void process_bingo(int(*p)[N], int num)
{
   int i, j;

   for (i = 0; i < N; i++)
   {
      	for (j = 0; j < N; j++)
      	{
        	if (p[i][j] == num)
            	break;
      	}
      	if (p[i][j] == num)
        	break;
   }
   p[i][j] = -1;
}
