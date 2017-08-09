#include <stdio.h>

double power(int n, int m)                // n^m
{
	int i, nt = 0;
	double pow = 1.0;

	if(m < 0)
	{
		m = -m;
		nt = 1;
	}


	for (i=0 ; i < m; ++i)
		pow *= n;

	if(nt)
		pow = 1/pow;

	return pow;
}

int main(void)
{
	int a;
	for(a=1; a<=10; a++)
		printf("2^%d = %f\n", -a, power(2, -a));
	return 0;
}



