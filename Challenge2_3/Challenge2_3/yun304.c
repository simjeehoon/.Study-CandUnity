#include "main.h"

int yun304()
{
	int dice1, dice2;

	srand((unsigned)time(NULL));
	
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	
	printf("�ֻ��� 1�� ��� : %d\n", dice1);
	printf("�ֻ��� 2�� ��� : %d\n", dice2);
	
	return 0;
}