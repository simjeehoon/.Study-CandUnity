#include "main.h"

void print(int (* box)[4]);

int yun301()
{
	int box[4][4];
	int i, j;

	printf("�迭 44 �Է�(�ڵ�)\n");
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			box[i][j] = (4*i)+j+1;
	}
	
	print(box);
	return 0;
}

void print(int (* box)[4])
{
	int i, j;
	printf("0��\n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			printf("%-2d ", box[i][j]);
		printf("\n");
	}

	printf("90��\n");
	
	for (i = 0; i < 4; i++) {
		for (j = 3; j >= 0; j--)
			printf("%-2d ", box[j][i]);
		printf("\n");
	}
	
	printf("180��\n");
	
	for (i = 3; i >= 0; i--) {
		for (j = 3; j >= 0; j--)
			printf("%-2d ", box[i][j]);
		printf("\n");
	}
	
	printf("270��\n");
	
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++)
			printf("%-2d ", box[j][i]);
		printf("\n");
	}
	

}