#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N	5
#define M	1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initiate_bingo(int(*p)[N], int N*N);
void print_bingo(int(*p)[N]);
int main(int argc, char *argv[])
{

   int num1, num2, i, j;
   int s[N][N], c[N][N];

   srand((unsigned)time(NULL));

   initiate_bingo(s, N*N);
   initiate_bingo(c, N*N);
   print_bingo(s);
   printf("\n");
   print_bingo(c);

   


   return 0;
}
void initiate_bingo(int(*p)[N], int N*N)
{
   int i, j;

   for (i = 0; i < N; i++)
   {
      for (j = 0; j < N; j++)
      {
         p[i][j] = 1 + rand() % (N*N);
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
         printf(" %2d ", p[i][j]);
      }
      printf("\n");
   }
}
