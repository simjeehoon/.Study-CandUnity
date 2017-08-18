#include "main.h"
int SquareByValue(int num);
void SquareByReference(int * num);

int yunm140101()
{
	int num;

	printf("num : ");
	scanf("%d", &num);
	num = SquareByValue(num);
	printf("%d\n", num);

	printf("num : ");
	scanf("%d", &num);
	SquareByReference(&num);
	printf("%d\n", num);

	return 0;
}

int SquareByValue(int num) {
	return num*num;
}

void SquareByReference(int * num) {
	*num *= *num;
}