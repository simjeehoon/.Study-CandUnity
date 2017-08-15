#include "main.h"

void print(int * box[4], int angle);

int yun301()
{
	int box[4][4];
	int i, j;
	printf("배열 44 입력\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			scanf("%d", &box[i]);
	}
	print(box, 0);
	return 0;
}

void print(int (* box)[4], int angle)
{
	int i, j;
	if (angle == 0)
	{
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				printf("%d ", box[i][j]);
			printf("\n");
		}
	}
}