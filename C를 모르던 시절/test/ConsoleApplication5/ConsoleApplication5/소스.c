#include <stdio.h>

int main(void)
{
	int n;
	int k = 0, powered = 1;
	do
	{
		printf("�Է� : ");
		scanf("%d", &n);
	} while (n <= 0);

	while (powered * 2 <= n)
	{
		powered *= 2;
		k++;
	}
	printf("������ �����ϴ� k�� �ִ��� %d\n", k);
	return 0;
}