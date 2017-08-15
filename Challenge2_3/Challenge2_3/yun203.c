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
	printf("총 10개의 숫자 입력\n");
	for (i = 0; i < 10; i++)
	{
		printf("입력: ");
		scanf("%d", &num);
		inputinarray(num, arr);
	}
	printf("배열 요소의 출력 : ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}