#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

int count_bingo(int(*p)[N])
{
   int i, j, binc = 0, cnt = 0;//binc�� bingo count 

   for (i = 0; i < N; i++)//�� ���� ��� -1���� Ȯ�����ش�
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
   
   for (j = 0; j < N; j++)//�� ���� ��� -1���� Ȯ�����ش�
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
   
   for (i = 0; i < N; i++)//����->���������� ���ϴ� �밢���� ��� -1���� Ȯ�����ش�
   {
      	if (p[i][i] == -1)
         	cnt++;
   }
   if (cnt == N)
    	binc++;
      
   cnt = 0;
   for (i = 0; i < N; i++)//������->�������� ���ϴ� �밢���� ��� -1���� Ȯ�����ش�
   {
      	if (p[i][N - 1 - i] == -1)
        	cnt++;
   }
   if (cnt == N)
    	binc++;

   return binc;
}
