#include <stdio.h>

int main(void)
{
	double n;
	_Bool negative = 0;
	int k = 0, powered = 1;
	do
	{
		printf("입력 : ");
		scanf("%d", &n);
	} while (n <= 0);

	if (n > 0 && n < 1)
	{
		negative = 1;
		n = 1 / n;
	}

	while (powered * 2 <= n)
	{
		powered *= 2;
		k++;
	}
	if (negative) k = -k;
	printf("공식을 만족하는 k의 최댓값은 %d\n", k);
	return 0;
}