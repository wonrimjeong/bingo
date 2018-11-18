#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void initiate_bingo(int(*p)[N]);
void print_bingo(int(*p)[N]);
int get_number_byMe();
int get_number_byCom(int(*p)[N]);
void process_bingo(int(*p)[N], int num);
int count_bingo(int(*p)[N]);
int main(int argc, char *argv[])
{

   int NUM, i, j;
   int s[N][N], c[N][N];

   srand((unsigned)time(NULL));

   initiate_bingo(s);
   initiate_bingo(c);
   print_bingo(s);
   printf("\n");
   print_bingo(c);
   printf("\n");

   while (1)
   {
      NUM = get_number_byMe();
      process_bingo(s, NUM);
      process_bingo(c, NUM);
      print_bingo(s);
      printf("\n");
      print_bingo(c);

      

   }


   return 0;
}
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
   int num, i, j, check=0, flag=0;
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
               return num;
            else
               check++;
         }
      }
      if (check == N * N)
         printf("이미 선택되었던 숫자입니다! 다시 입력해주세요:");
      check = 0;
      
   }

   return num;
}

int get_number_byCom(int(*p)[N])
{
   int i, j, ran, check=0;

   while (1)
   {
      ran = 1 + rand() % (N*N);
      for (i = 0; i < N; i++)
      {
         for (j = 0; j < N; j++)
         {
            if (p[i][j] == ran)
               break;
            else
               check++;
         }
         if (p[i][j] == ran)
            break;
      }
      if (p[i][j] == ran)
         return ran;
      check = 0;
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
   int i, j, binc = 0, cnt = 0;

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

