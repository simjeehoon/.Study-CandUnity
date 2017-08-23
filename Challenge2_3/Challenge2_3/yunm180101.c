#include "main.h"

int yunm180101() {
	int * arr1[5];
	int * arr2[3][5];

	int ** ptr1 = arr1;
	int *(*ptr2)[5] = arr2;

	int i, j;
	int num[15] = { 1, 2, 3, 4, 5 };
	int num2[3][5] = { {11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35} };
	/*
	for (i = 0; i < 5; i++)
		ptr1[i] = &num[i];
	for (i = 0; i < 5; i++)
		printf("%d\n", *ptr1[i]);
		*/
	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			ptr2[i][j] = &num2[i][j];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++)
			printf("%d ", *ptr2[i][j]);
		printf("\n");
	}
	return 0;
}