#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

void initiate_bingo(int(*p)[N])
{
   int i, j, k, ran, cnt=0, check=0;
   int tmp[N*N] = { 0 };

   for (i = 0; i < N; i++)
   {
      for (j = 0; j < N; j++)
      {
         while (1)
         {
            ran = 1 + rand() % (N*N);
            for (k = 0; k < cnt; k++)
            {
               if (tmp[k] == ran)
                  break;
               else
                  check++;
            }
            if (check == cnt)
            {
               check = 0;
               break;
            }
            else
               check = 0;
         }
         p[i][j] = ran;
         tmp[cnt]= ran;
         cnt++;
      }
   }
}
