#include "main.h"
void swap3(int * num1, int * num2, int * num3)
{
	int tmp = *num3;
	*num3 = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

int yunm140102()
{
	int num1=1, num2=2, num3=3;
	printf("%d %d %d\n", num1, num2, num3);
	swap3(&num1, &num2, &num3);
	printf("%d %d %d\n", num1, num2, num3);

	return 0;
}
