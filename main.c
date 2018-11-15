#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N	5
#define M	1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j, bFound;
	int s[i][j];
	int max = N*N;
	
	srand((unsigned)time(NULL)); //시간이용하여 난수 
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			s[i][j] = 1+rand()%max;
		}
	}
	
	 for ( i = 0; i < 10; ++i )

       {
			while ( 1 )

    	{// 난수를하나생성
		srand[i][j] = rand() % max + 1;
		bFound = 0;

		for ( j = 0; j < i; ++j )
		{
			if ( srand[j] == srand[i] )
			{
				 bFound = 1;
					break;
			}
        }
			 if ( !bFound )
			     break;
		}
}

 

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" %d ", s[i][j]);
		}
		printf("\n"); // 빙고판 생성 
	}
	return 0;

}
