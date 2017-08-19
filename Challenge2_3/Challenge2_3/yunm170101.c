#include "main.h"

void MaxAndMin(int arr[], int ** M, int ** m);

int yunm170101()
{
	int *maxPtr, *minPtr;
	int arr[5];
	int i;
	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	MaxAndMin(arr, &maxPtr, &minPtr);

	printf("max = %d, min = %d", *maxPtr, *minPtr);

	return 0;
}

void MaxAndMin(int arr[], int ** M, int ** m) {
	int *max, *min;
	int i;
	
	max = min = &arr[0];

	for (i = 1; i < 5; i++)
	{
		if (*max < arr[i]) {
			max = &arr[i];
		}
		if (*min > arr[i]) {
			min = &arr[i];
		}
	}
	*M = max;
	*m = min;
}