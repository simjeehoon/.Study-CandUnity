#include "main.h"

void snail(int, int**);
int** allocation(int);
void allocfree(void** );

int yun302()
{
	int num;
	int **arr;

	printf("숫자를 입력하시오 : ");
	scanf("%d", &num);
	if (num > 0) {
		arr = allocation(num);
		snail(num, arr);
		allocfree(arr);
	}
	return 0;
}

void snail(int num, int** arr)
{
	int i = 0, j = 0;
	int level = 0;
	int count = 0;
	arr[0][0] = ++count;
	while (count < num*num)
	{
		for (j+=1; j < num - level; j++) {
			arr[i][j] = ++count;
		}
		j--;
		for (i+=1; i < num - level; i++) {
			arr[i][j] = ++count;
		}
		i--;
		for (j-=1; j >= level; j--) {
			arr[i][j] = ++count;
		}
		j++;
		for (i-=1; i >= 1 + level; i--) {
			arr[i][j] = ++count;
		}
		i++;
		level++;
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
			printf("%2d ", arr[i][j]);
			printf("\n");
	}
}

int** allocation(int num)
{
	int **arr;
	int i;

	arr = (int**)malloc(sizeof(int)*num);
	arr[0] = (int*)malloc(sizeof(int)*num*num);
	for (i = 1; i < num; i++)
		arr[i] = arr[i - 1] + num;

	return arr;
}

void allocfree(void** arr)
{
	free(arr[0]);
	free(arr);
}
