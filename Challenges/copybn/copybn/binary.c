#include <stdio.h>

int main(void)
{
	FILE * origin = fopen("f.bmp", "rt");
	FILE * copy = fopen("a.bmp", "wt");

	char buf[20];
	int readCnt;

	if (origin == NULL || copy == NULL) {
		puts("�о���� ����");
		return -1;
	}

	while (1) {
		readCnt = fread((void *)buf, 1, sizeof(buf), origin);
		if (readCnt < sizeof(buf)) 
		{
			if (feof(origin) != 0) {
				fwrite((void *)buf, 1, readCnt, copy);
				puts("���� �Ϸ�");
				break;
			}
			else {
				puts("���� ����");
			}
			break;
		}
		fwrite((void *)buf, 1, sizeof(buf), copy);
	}
	fclose(origin);
	fclose(copy);

	return 0;
}