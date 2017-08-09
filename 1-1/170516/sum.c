#include <stdio.h>

int add2(int xx, int yy)
{
	xx = xx + yy;
	return xx;
}

int main(void){
	int i, sum, num;
	scanf("%d", &num);
	for (i = 0, sum = 0; i <= num; i++) {
		sum = 	add2(sum, i);
	}
	printf("The sum(0:%d) = %d\n", num, sum);
	return 0;
}


