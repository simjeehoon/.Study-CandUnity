#include <stdio.h>
#include <stdlib.h>

int ym2522()
{
	int num;
	int i = 0, j = 0;
	int max = 5;
	int * arr = (int *)malloc(max * sizeof(int));
	
	while (1)
	{
		printf("%d번째 정수 입력: ", i+1);
		scanf("%d", &num);
		arr[i++] = num;
		if (num == -1)
			break;
		if (i >= max)
		{
			max += 3;
			arr = (int *)realloc(arr, max * sizeof(int));
		}
	}
	
	for (j = 0; j < i; j++)
	{
		printf("[%d] = %d\n", j+1, arr[j]);
	}
	
	free(arr);
	return 0;
}