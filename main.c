#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initiate_bingo.h"
#include "print_bingo.h"
#include "get_number_byMe.h"
#include "get_number_byCom.h"
#include "process_bingo.h"
#include "count_bingo.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initiate_bingo(int(*p)[N]);
void print_bingo(int(*p)[N]);
int get_number_byMe(int(*p)[N]);
int get_number_byCom(int(*p)[N]);
void process_bingo(int(*p)[N], int num);
int count_bingo(int(*p)[N]);

int main(int argc, char *argv[])
{

   int NUM, turn = 1; 
   int me[N][N], com[N][N];

   srand((unsigned)time(NULL));

   initiate_bingo(me);
   initiate_bingo(com);

   while (1)
   {
    	print_bingo(me);
      	printf("\n");
      	NUM = get_number_byMe(me); //NUM은 get_number_byMe에서 받은 숫자
      	process_bingo(me, NUM);
      	process_bingo(com, NUM);
      	
      	if (count_bingo(me) >= M)
      	{
        	printf("승리자는 '나'이고, %d번째 turn에서 승부가 났습니다.", turn);
        	return 0;
      	}
      	if (count_bingo(com) >= M)
      	{
        	printf("승리자는 '상대방'이고, %d번째 turn에서 승부가 났습니다.", turn);
        	return 0;
      	}
      	
    	NUM = get_number_byCom(com);
      	printf("상대방이 선택한 숫자는 %d입니다.\n\n", NUM);
      	process_bingo(me, NUM);
      	process_bingo(com, NUM);
      	
      	if (count_bingo(me) >= M)
      	{
         	printf("승리자는 '나'이고, %d번째 turn에서 승부가 났습니다.", turn);
         	return 0;
      	}
      	if (count_bingo(com) >= M)
      	{
        	printf("승리자는 '상대방'이고, %d번째 turn에서 승부가 났습니다.", turn);
      	  	return 0;
      	}
      	turn++;
	}
}

void initiate_bingo(int(*p)[N])
{
   int i, j, k, ran, cnt = 0, check = 0; //check는 ran과 이미 들어가있는 숫자를 비교한 횟수, cnt는 이미 들어가있는 숫자의 갯수 
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
         tmp[cnt] = ran;
         cnt++; 
      }
   }
}

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

int get_number_byMe(int(*p)[N])
{
   int num, i, j, check = 0;
   printf("숫자를 선택하세요:");
   
   while (1)
   {
      	scanf("%d", &num);
      	if (num<1 || num>N*N)
      	{
         	printf("범위 밖의 숫자입니다! 다시 입력해주세요:");
         	continue;
     	}
      	for (i = 0; i < N; i++)
      	{
        	for (j = 0; j < N; j++)
        	{
            	if (p[i][j] == num)
               		return num; //Me에게 받은 숫자가 2차원행렬 빙고판에 있으면 메인함수로 반환해준다.  
            	else
               		check++;//행렬에 있는 숫자와 내가 선택한 숫자가 같았던 횟수 
        	}
      	}
      	if (check == N * N)//선택한 숫자가 행렬에 있는 숫자와 N*N개 만큼 중복되는지 확인 
		printf("이미 선택되었던 숫자입니다! 다시 입력해주세요:");
		
      	check = 0;
	}
}

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
      	if (p[i][j] == ran) //난수로 발생시킨 수가 2차원행렬의 빙고판에 있는지 확인 
        
		return ran;
   }
}

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
