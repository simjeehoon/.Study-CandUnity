#include <stdio.h>

int main(void)
{
	int y, x;
	double z;

	printf("y(int형) 입력 : ");
	scanf("%d", &y);

	printf("z(double형) 입력 : ");
	scanf("%f", &z);

	x = (y > z) ? y : z;

	printf("더큰값 : %d\n", x);

	printf("사이즈오브x : %d,  사이즈오브 : %d ", sizeof(x)
			,sizeof((y > z) ? y : z));
	printf(" \nint : %d  double : %d,   longdouble %d\n", sizeof(int), sizeof(double), sizeof(long double));

	return 0;
}

