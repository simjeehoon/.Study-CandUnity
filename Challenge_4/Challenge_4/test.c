#include <stdio.h>
#include "virtual effect.h"

void reset_scanf()
{
	while (getchar() != '\n')
		;
}

int give_plus(int num) {
	return num+1;
}
int testfunc001() {
	return give_plus(0);
}
int test2()
{
	Color cr = 0;

	printf("test function\n");
	for (cr = 0; cr <= 15; cr++) {
		SetColor(cr);
		printf("%d Â° »ö±ò color\n", cr);
	}
	return 0;
}

int test3()
{
	int num;
	int i;
	char str[10] = { 0 };
	printf("TEST : %d", testfunc001());
	gets(str);

	for (i = 0; i < 10; i++)
	{
		printf("str[%d] = %d\n", i, str[i]);
	}
	return 0;
}

