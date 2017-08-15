#include "main.h"

int checkHM(char[]);

int yun204()
{
	char text[100];
	printf("회문 테스트 : ");
	scanf("%s", text);
	if (checkHM(text))
		printf("회문이 아닙니다.\n");
	else
		printf("회문입니다.\n");
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