#include <time.h>
#include <stdio.h>
#define N 1000000000
int main(){
	int x = 0, y = 0, i;
	clock_t a,b,c,d;

	printf("정수를 입력하세요 : ");
	scanf("%d", &x);

	a= clock();
	for (i = 0; i < N; i++){
		switch(x){
		case 0: y += 2;
		break;
		case 1: y += 1;
				break;
		default :y += -1;
		}
	}
	b= clock();
	

	c = b-a;

	printf("sum = %d\n", y);
	printf("실행시간 : %d 클록\n",c); 
	d=c/CLOCKS_PER_SEC;
	printf("실행시간 : %d 초\n", d);

	return 0;
}


