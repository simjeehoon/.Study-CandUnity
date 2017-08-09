#include <stdio.h>

int a = 0, b = 0, c = 0;

void doing (void)
{
	int b = 3;
	a= 1;

	return ;
	c=300;
}


int main(void)
{
	printf("함수 호출 전 a = %d,  b = %d, c = %d \n", a, b, c);
	doing();
	printf("함수 호출 후 a = %d,  b = %d, c = %d \n", a, b, c);
	return 0;
}
