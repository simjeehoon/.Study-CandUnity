#include <stdio.h>

void bufferreset();

typedef struct employee {
	char name[20];
	char number[20];
	int pay;
}Employee;

int yunm220101()
{
	Employee men[3];
	int i;
	bufferreset();

	for (i = 0; i < 3; i++) {
		printf("%d�� �̸� : ", i+1);
		scanf("%s", &men[i].name);
		printf("%d�� �ֹι�ȣ : ", i+1);
		scanf("%s", &men[i].number);
		printf("%d�� �޿����� : ", i+1);
		scanf("%d", &men[i].pay);
	}
	for (i = 0; i<3;i++)
		printf("�̸� : %s\n�ֹι�ȣ : %s\n�޿����� : %d\n", men[i].name, men[i].number, men[i].pay);
	return 0;
}