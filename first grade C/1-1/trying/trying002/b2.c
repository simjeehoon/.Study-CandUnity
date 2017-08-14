#include <stdio.h>

int main(void)
{
	unsigned long long l = 8989898989898;
	double x  = 1.0;

	printf("%lld\n%f\n%f\n%lld", l, x, l+x, l+x);
	return 0;
}



