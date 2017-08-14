#include <stdio.h>
int my_abs(int x)
{
	if (x>=0)
		return x;
	else
		return -x;
}

int main(void)
{
	printf("1의 절대값 : %d\n", my_abs(1));
	printf("-8의 절대값 : %d\n", my_abs(-8));
	return 0;
}

