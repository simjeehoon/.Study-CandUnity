#include <stdio.h>
#include <float.h>


int main(void)
{
	float f;
	double d;
	long double ld;
	scanf("%f %lf %Lf",&f, &d, &ld);
	printf("%.30f \n%.30f \n%.30Lf",	f, d, ld);

	return 0;

}

