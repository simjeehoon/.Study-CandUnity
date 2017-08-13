#include <stdio.h>
int try = 0; // 횟수를 세기 위한 전역변수 사용.
             // hanoi 함수 내에서 원반을 옮길 때마다
      		 // 값을 1씩 증가시키고
			 // 마지막에 최종 시도 횟수를 출력한다.
void hanoi(int, int, int, int);

int main(void)
{
	int n;
		printf("하노이탑의 층 수 : ");
		scanf("%d", &n);

	hanoi(n, 1, 2, 3);   //하노이 타워 알고리즘 시작
	printf("\n총 시도 횟수 : %d\n", try);   //하노이 타워의 시도 횟수 출력
	return 0;
}

void hanoi(int n, int from, int tmp, int to)    //하노이 타워 알고리즘
{      /* 각각의 변수는 하노이 타워의 원반 수, 시작 기둥, 임시 기둥, 목표 기둥을 의미함.*/
	if (n == 1)
		printf("%d. 원반 1를 %d번 기둥에서 %d번 기둥으로 옮긴다.\n", ++try, from, to); //1개이면 즉시 to로 옮긴다.
	else{  
		hanoi(n-1, from, to, tmp);                //원반 n 위의 n-1개의 원반들을 tmp로 옮긴다.
		printf("%d. 원반 %d를 %d번 기둥에서 %d번 기둥으로 옮긴다.\n", ++try, n, from, to); //원반 n을 to로 옮긴다.
		hanoi(n-1, tmp, from, to);                //tmp에 있던 n-1개의 원반들을 다시 to로 옮긴다.
	}
	return ;

}

