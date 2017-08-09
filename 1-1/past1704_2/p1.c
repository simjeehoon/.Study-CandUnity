#include <stdio.h>

int main(void)
{
	/*
	   *
	   *  단축평가 예제
	   *
	   */

	int i = 4, j = 5;

	i == 4 || (j = 6);
	printf("j = %4d\n", j);

	i == 3 && (j = 9);
	printf("j = %4d\n", j);

	return 0;
}

