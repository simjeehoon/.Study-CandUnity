#include "main.h"

int checkHM(char[]);

int yun204()
{
	char text[100];
	printf("ȸ�� �׽�Ʈ : ");
	scanf("%s", text);
	if (checkHM(text))
		printf("ȸ���� �ƴմϴ�.\n");
	else
		printf("ȸ���Դϴ�.\n");
	return 0;
}

int checkHM(char text[]) {
	int i;
	int length = strlen(text);
	
	for (i = 0; i < length / 2 ; i++)
	{
		if (text[i] != text[length - 1 - i])
			return -1;
	}
	return 0;

}