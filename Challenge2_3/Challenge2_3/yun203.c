#include "main.h"

void inputinarray(int num, int arr[])
{
	static odd_i = 0;
	static even_i = 9;
	if (num % 2)
		arr[odd_i++] = num;
	else
		arr[even_i--] = num;
}

int yun203(void)
{
	int arr[10];
	int i;
	int num;
	printf("�� 10���� ���� �Է�\n");
	for (i = 0; i < 10; i++)
	{
		printf("�Է�: ");
		scanf("%d", &num);
		inputinarray(num, arr);
	}
	printf("�迭 ����� ��� : ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}