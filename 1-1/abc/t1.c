#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int inp=101, res, count=0;
	srand(time(NULL));
	if ((rand()%100)>50)
	printf("주문서 성공!\n"); 
	else
	printf("주문서 실패!\n"); 
	/*
	printf("1부터 100까지 정수중 하나를 맞추기\n정수를 입력하세요 : ");
	while(inp != res)
	{
	++count;
	scanf("%d", &inp);
	if(inp == res)
		printf("정답! %d, \n총 시도횟수는 %d번 입니다. \n", res, count);
	else if(res > inp)
		printf("정답은 그것보다 크다. 현재까지 %d번 시도하였다.\n정수를 입력하세요 : ", count);
	else if(res < inp)
		printf("정답은 그것보다 작다. 현재까지 %d번 시도하였다.\n정수를 입력하세요 : ", count);
	}
	*/
	return 0;
}

