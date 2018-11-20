#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

int get_number_byCom(int(*p)[N])
{
   int i, j, ran;

   while (1)
   {
      ran = 1 + rand() % (N*N);
      for (i = 0; i < N; i++)
      {
         for (j = 0; j < N; j++)
         {
            if (p[i][j] == ran)
               break;
         }
         if (p[i][j] == ran)
            break;
      }
      if (p[i][j] == ran)
         return ran;
   }

}
