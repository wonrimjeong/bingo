#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5
#define M   1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void initiate_bingo(int(*p)[N]);
void print_bingo(int(*p)[N]);
int get_number_byMe();
int get_number_byCom();
void process_bingo(int num);
int count_bingo(int(*p)[N]);
int main(int argc, char *argv[])
{

   int num1, num2, i, j;
   int s[N][N], c[N][N];

   srand((unsigned)time(NULL));

   initiate_bingo(s);
   initiate_bingo(c);
   print_bingo(s);
   printf("\n");
   print_bingo(c);

   while (1)
   {
      num1 = get_number_byMe();
      num2 = get_number_byCom();
      process_bingo(num1);
      process_bingo(num2);


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
         ran = 1 + rand() % (N*N);
         while (1)
         {
            for (k = 0; k < cnt; k++)
            {
               if (tmp[k] == ran)
               {
                  ran = 1 + rand() % (N*N);
                  break;
               }
               else
                  check++;
            }
            if (check == cnt)
               break;
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
      {
         printf("%3d", p[i][j]);
      }
      printf("\n");
   }
}
int get_number_byMe()
{
   int num;
   printf("숫자를 선택하세요:");
   scanf("%d", &num);
   return num;
}
int get_number_byCom()
{
   return rand() % (N*N);
}
void process_bingo(int num)
{

}
