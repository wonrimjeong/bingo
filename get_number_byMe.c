#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "get_number_byMe.h"

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
               		return num;
            	else
               		check++;//행렬에 있는 숫자와 내가 선택한 숫자가 같았던 횟수 
        	}
      	}
      	if (check == N * N)//선택한 숫자가 행렬에 있는 숫자와 N*N개 만큼 중복되는지 확인 
		printf("이미 선택되었던 숫자입니다! 다시 입력해주세요:");
		
      	check = 0;
	}
}
