#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "get_number_byMe.h"

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
      	if (check == N * N)//������ ���ڰ� ��Ŀ� �ִ� ���ڿ� N*N�� ��ŭ �ߺ��Ǵ��� Ȯ�� 
		printf("�̹� ���õǾ��� �����Դϴ�! �ٽ� �Է����ּ���:");
		
      	check = 0;
	}
}
