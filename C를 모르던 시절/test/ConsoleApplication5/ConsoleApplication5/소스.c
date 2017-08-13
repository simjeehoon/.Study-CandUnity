#include <stdio.h>

int main(void)
{
	int n;
	int k = 0, powered = 1;
	do
	{
		printf("입력 : ");
		scanf("%d", &n);
	} while (n <= 0);

	while (powered * 2 <= n)
	{
		powered *= 2;
		k++;
	}
	printf("공식을 만족하는 k의 최댓값은 %d\n", k);
	return 0;
}