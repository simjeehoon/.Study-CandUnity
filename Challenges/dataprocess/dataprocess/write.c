#include <stdio.h>
#include "struct.h"
void bufferreset();

int write() {
	FILE * wtp;
	Friend Wfr;
	char filename[100] = { 0 };

	printf("���� �Լ� ����\n");
	printf("�� ���� �̸��� �����Ͻÿ�.(30���̳�)\n���� �̸�: ");
	scanf("%s", filename);
	bufferreset();

	strcat(filename, ".bin");
	
	wtp = fopen(filename, "wb");
	if (wtp == NULL) {
		printf("���� ������ �����߽��ϴ�.\n");
		return -1;
	}

	printf("�̸�, ����, ���̸� ������� ���ÿ� :");
	scanf("%s %c %d", Wfr.name, &(Wfr.sex), &(Wfr.age));
	bufferreset();

	fwrite((void *)&Wfr, sizeof(Wfr), 1, wtp);
	fclose(wtp);

	printf("%s �ۼ� �Ϸ�Ǿ����ϴ�.\n", filename);
	return 0;
}