#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

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
               return num;
            else
               check++;//��Ŀ� �ִ� ���ڿ� ���� ������ ���ڰ� ���Ҵ� Ƚ�� 
         }
      }
      if (check == N * N)//��Ŀ� �ִ� ���ڰ� N*N�� 
         printf("�̹� ���õǾ��� �����Դϴ�! �ٽ� �Է����ּ���:");
      check = 0;

   }
}
