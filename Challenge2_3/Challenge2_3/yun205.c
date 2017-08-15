#include "main.h"


void bubblesort(int *, int);

int yun205()
{
	int arr[7];
	int i;
	for (i = 0; i < 7; ++i) {
		printf("ют╥б :");
		scanf("%d", &arr[i]);
	}

	bubblesort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 7; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

void bubblesort(int * arr, int length)
{
	int i, j;
	int tmp;
	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < (length - i) - 1; j++) {
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
