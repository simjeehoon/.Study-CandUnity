#include <stdio.h>
#include "struct.h"

void bufferreset();
int read()
{
	FILE * rtp;
	Friend Rfr;
	char filename[100] = { 0 };
	printf("�б� �Լ� ����\n");
	printf("���� ���� �̸��� �Է�(30���̳�)\n���� �̸�: ");
	scanf("%s", filename);
	bufferreset();

	strcat(filename, ".bin");
	rtp = fopen(filename, "rb");

	if (rtp == NULL) {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		return -1;
	}
	fread((void *)&Rfr, sizeof(Friend), 1, rtp);

	printf("%s �� �����Դϴ�.\n", filename);
	printf("�̸� : %s\n���� : %c\n���� : %d\n", Rfr.name, Rfr.sex, Rfr.age);
	
	fclose(rtp);
	
	return 0;

}