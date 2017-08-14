#include <stdio.h>

double power(double x, int n)
{
	int i;
	double res = 1.0;	
	for(i = 0; i < n; i++)
		res *= x;
	return res;
}

int main(void)
{
	printf("%.7f\n", power(3.5, 7));
	printf("%.7f", 3.5*3.5*3.5*3.5*3.5*3.5*3.5);

	return 0;
}
