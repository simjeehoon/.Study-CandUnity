#include <stdio.h>

int add2(int num)
{
	int i, sum;

	for(i=0, sum=0;i<=num;i++)
		sum=sum+i;
	return sum;
}

int main(void){
	int i, sum, num;
	scanf("%d", &num);
	sum = add2(num);
	printf("The sum(0:%d) = %d\n", num, sum);
	return 0;
}


