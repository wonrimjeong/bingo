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
      	NUM = get_number_byMe(me); //NUM�� get_number_byMe���� ���� ����
      	process_bingo(me, NUM);
      	process_bingo(com, NUM);
      	
      	if (count_bingo(me) >= M)
      	{
        	printf("�¸��ڴ� '��'�̰�, %d��° turn���� �ºΰ� �����ϴ�.", turn);
        	return 0;
      	}
      	if (count_bingo(com) >= M)
      	{
        	printf("�¸��ڴ� '����'�̰�, %d��° turn���� �ºΰ� �����ϴ�.", turn);
        	return 0;
      	}
      	
    	NUM = get_number_byCom(com);
      	printf("������ ������ ���ڴ� %d�Դϴ�.\n\n", NUM);
      	process_bingo(me, NUM);
      	process_bingo(com, NUM);
      	
      	if (count_bingo(me) >= M)
      	{
         	printf("�¸��ڴ� '��'�̰�, %d��° turn���� �ºΰ� �����ϴ�.", turn);
         	return 0;
      	}
      	if (count_bingo(com) >= M)
      	{
        	printf("�¸��ڴ� '����'�̰�, %d��° turn���� �ºΰ� �����ϴ�.", turn);
      	  	return 0;
      	}
      	turn++;
	}
}

void initiate_bingo(int(*p)[N])
{
   int i, j, k, ran, cnt = 0, check = 0; //check�� ran�� �̹� ���ִ� ���ڸ� ���� Ƚ��, cnt�� �̹� ���ִ� ������ ���� 
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
   printf("���ڸ� �����ϼ���:");
   
   while (1)
   {
      	scanf("%d", &num);
      	if (num<1 || num>N*N)
      	{
         	printf("���� ���� �����Դϴ�! �ٽ� �Է����ּ���:");
         	continue;
     	}
      	for (i = 0; i < N; i++)
      	{
        	for (j = 0; j < N; j++)
        	{
            	if (p[i][j] == num)
               		return num; //Me���� ���� ���ڰ� 2������� �����ǿ� ������ �����Լ��� ��ȯ���ش�.  
            	else
               		check++;//��Ŀ� �ִ� ���ڿ� ���� ������ ���ڰ� ���Ҵ� Ƚ�� 
        	}
      	}
      	if (check == N * N)//������ ���ڰ� ��Ŀ� �ִ� ���ڿ� N*N�� ��ŭ �ߺ��Ǵ��� Ȯ�� 
		printf("�̹� ���õǾ��� �����Դϴ�! �ٽ� �Է����ּ���:");
		
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
      	if (p[i][j] == ran) //������ �߻���Ų ���� 2��������� �����ǿ� �ִ��� Ȯ�� 
        
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
