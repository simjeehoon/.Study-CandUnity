#include <stdio.h>
int a = 0, b = 0, c = 0;
int f(void);

int main(void){
	a = 1;
	b = 2;
	printf("a + b = %d\n", f());
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	return 0;
}
int f(void)
{
	int c;             //lcoal variable
	c = a + b;
	return c;
}


