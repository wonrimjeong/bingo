#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N	5
#define M	1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int i, j, x;
	int arr[i][j];
	int max = N*N;
	int dup_check(int row, int col, int x);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			 while (1) //중복체크 무한루프 
			{
				x= rand()%(N*N)+1;
				if( dup_check(i,j,x) == 0 ) //중복이 아니라면 
				break;
			}

 			arr[]i][j]=x;
		}

 	}

	return 0;	
	

int dup_check(int row, int col, int x)
	{
		int i=0,j=0;

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if (arr[i][j]==x) // 배열에 저장된 난수와 현재난수가 같으면
				{
					return 1; //중복을 알려준다. 
				}
			}
		}
		return 0;	
	}


int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL)); //시간이용하여 난수발생 
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			arr[i][j] = 1+rand()%max;
		}
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" %d ", arr[i][j]);
		}
		printf("\n"); // 빙고판 생성 
	}
	
	return 0;
