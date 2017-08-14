#include <stdio.h>

void hanoi(int,int,int,int);

int main(void)
{
	int n;
	do
	{
		printf("하노이탑의 층 수 : ");
		scanf("%d", &n);
		if(n<=0)
			printf("양의 정수를 입력해주세요.\n");
	}while (n<=0);   //양의 정수만을 받기 위한 반복문

	hanoi(n, 1, 2, 3);   //하노이 타워 알고리즘 시작
	//printf("\n총 시도 횟수 : %d\n", count);   //하노이 타워의 시도 횟수 출력
	return 0;
}

void hanoi(int n, int from, int tmp, int to)    //하노이 타워 알고리즘
{      /* 각각의 변수는 하노이 타워의 원반 수, 시작 기둥, 임시 기둥, 목표 기둥을 의미함.*/
	
	static int count = 0;

	if (n == 1)
		printf("%d. 원반 1를 %d번 기둥에서 %d번 기둥으로 옮긴다.\n", ++count, from, to); //1개이면 즉시 to로 옮긴다.
	else{  
		hanoi(n-1, from, to, tmp);                //원반 n 위의 n-1개의 원반들을 tmp로 옮긴다.
		printf("%d. 원반 %d를 %d번 기둥에서 %d번 기둥으로 옮긴다.\n", ++count, n, from, to); //원반 n을 to로 옮긴다.
		hanoi(n-1, tmp, from, to);                //tmp에 있던 n-1개의 원반들을 다시 to로 옮긴다.
	}
	return ;

}

