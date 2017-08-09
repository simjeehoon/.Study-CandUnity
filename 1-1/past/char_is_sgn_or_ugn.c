#include <stdio.h>

int main(void)
{
	int val1=-1, val2=-1;
	char a=0xff;
	signed char b=0xff;
	unsigned char c=0xff;
	val1 = a == b;
	val2 = a == c;
	printf("%d %d", val1, val2);
	return 0;

}

