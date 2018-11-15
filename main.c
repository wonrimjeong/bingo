#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N	5
#define M	1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j;
	int s[i][j];
	int max = N*N;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			s[i][j] = 1+rand()%max;
		}
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" %d ", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
