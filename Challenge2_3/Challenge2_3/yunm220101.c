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
		printf("%d의 이름 : ", i+1);
		scanf("%s", &men[i].name);
		printf("%d의 주민번호 : ", i+1);
		scanf("%s", &men[i].number);
		printf("%d의 급여정보 : ", i+1);
		scanf("%d", &men[i].pay);
	}
	for (i = 0; i<3;i++)
		printf("이름 : %s\n주민번호 : %s\n급여정보 : %d\n", men[i].name, men[i].number, men[i].pay);
	return 0;
}