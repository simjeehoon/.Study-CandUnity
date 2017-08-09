#include <stdio.h>

void fib(int);
	
int main(void)
{
	int a;
	scanf("%d", &a);
	//for(i=0; i<a; i++)
	//	printf("f(%d) = %d\n", i, fib(i));
	fib(a);
	return 0;
}

void fib(int n)
{
		
/*	if (n==0)
		printf("f(0) = 0\n");
	else if (n==1)
		printf("f(1) = 1\n");
	else
		return fib(n-1)+fib(n-2);
*/	
	int i,z,x=0,y=1;
	if(n>=1)
	{	printf("f(0) = 0\n");
	if(n>=2)
			printf("f(1) = 1\n");
}
	for (i = 1; i<(n-1); i++)
	{
		z = x+y;
		x = y;
		y = z;
		printf("f(%d) = %d\n", i+1, y);
	}

	return;
}	

