#include <stdio.h>

int main(void)
{
	int a = 0;
	int *pa = &a;

	printf("%d", sizeof(*pa));
	return 0;
}


