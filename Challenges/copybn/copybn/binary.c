#include <stdio.h>

int main(void)
{
	FILE * origin = fopen("f.bmp", "rt");
	FILE * copy = fopen("a.bmp", "wt");

	char buf[20];
	int readCnt;

	if (origin == NULL || copy == NULL) {
		puts("읽어오기 실패");
		return -1;
	}

	while (1) {
		readCnt = fread((void *)buf, 1, sizeof(buf), origin);
		if (readCnt < sizeof(buf)) 
		{
			if (feof(origin) != 0) {
				fwrite((void *)buf, 1, readCnt, copy);
				puts("복사 완료");
				break;
			}
			else {
				puts("복사 실패");
			}
			break;
		}
		fwrite((void *)buf, 1, sizeof(buf), copy);
	}
	fclose(origin);
	fclose(copy);

	return 0;
}