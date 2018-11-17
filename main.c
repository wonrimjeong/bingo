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
			 while (1) //�ߺ�üũ ���ѷ��� 
			{
				x= rand()%(N*N)+1;
				if( dup_check(i,j,x) == 0 ) //�ߺ��� �ƴ϶�� 
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
				if (arr[i][j]==x) // �迭�� ����� ������ ���糭���� ������
				{
					return 1; //�ߺ��� �˷��ش�. 
				}
			}
		}
		return 0;	
	}


int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL)); //�ð��̿��Ͽ� �����߻� 
	
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
		printf("\n"); // ������ ���� 
	}
	
	return 0;
