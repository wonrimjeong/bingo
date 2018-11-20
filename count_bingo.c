#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

int count_bingo(int(*p)[N])
{
   int i, j, binc = 0, cnt = 0;//binc는 bingo count 

   for (i = 0; i < N; i++)//한 행이 모두 -1인지 확인해준다
   {
      	for (j = 0; j < N; j++)
      	{
        	if (p[i][j] == -1)
            	cnt++;
      	}
      	if (cnt == N)
        	binc++;
        
      	cnt = 0;
   }
   
   for (j = 0; j < N; j++)//한 열이 모두 -1인지 확인해준다
   {
      	for (i = 0; i < N; i++)
      	{
        	if (p[i][j] == -1)
            	cnt++;
      	}
      	if (cnt == N)
         	binc++;
      	
		cnt = 0;
   }
   
   for (i = 0; i < N; i++)//왼쪽->오른쪽으로 향하는 대각선이 모두 -1인지 확인해준다
   {
      	if (p[i][i] == -1)
         	cnt++;
   }
   if (cnt == N)
    	binc++;
      
   cnt = 0;
   for (i = 0; i < N; i++)//오른쪽->왼쪽으로 향하는 대각선이 모두 -1인지 확인해준다
   {
      	if (p[i][N - 1 - i] == -1)
        	cnt++;
   }
   if (cnt == N)
    	binc++;

   return binc;
}
