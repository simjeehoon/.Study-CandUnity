#include <stdio.h>
#include "struct.h"

void bufferreset();
int read()
{
	FILE * rtp;
	Friend Rfr;
	char filename[100] = { 0 };
	printf("읽기 함수 실행\n");
	printf("읽을 파일 이름이 입력(30자이내)\n파일 이름: ");
	scanf("%s", filename);
	bufferreset();

	strcat(filename, ".bin");
	rtp = fopen(filename, "rb");

	if (rtp == NULL) {
		printf("파일 열기에 실패했습니다.\n");
		return -1;
	}
	fread((void *)&Rfr, sizeof(Friend), 1, rtp);

	printf("%s 의 정보입니다.\n", filename);
	printf("이름 : %s\n성별 : %c\n나이 : %d\n", Rfr.name, Rfr.sex, Rfr.age);
	
	fclose(rtp);
	
	return 0;

}