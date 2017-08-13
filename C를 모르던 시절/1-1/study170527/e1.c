#include <stdio.h>

int main(void)
{
	int a= 10;
	int *pa = &a;

	printf("%d\n", a);
	printf("%#x\n", pa);
	printf("%p\n", pa);
	return 0;
}
