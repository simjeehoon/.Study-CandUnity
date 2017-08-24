#include <stdio.h>
#include "struct.h"
void bufferreset();

int write() {
	FILE * wtp;
	Friend Wfr;
	char filename[100] = { 0 };

	printf("쓰기 함수 실행\n");
	printf("쓸 파일 이름을 설정하시오.(30자이내)\n파일 이름: ");
	scanf("%s", filename);
	bufferreset();

	strcat(filename, ".bin");
	
	wtp = fopen(filename, "wb");
	if (wtp == NULL) {
		printf("파일 생성에 실패했습니다.\n");
		return -1;
	}

	printf("이름, 성별, 나이를 순서대로 쓰시오 :");
	scanf("%s %c %d", Wfr.name, &(Wfr.sex), &(Wfr.age));
	bufferreset();

	fwrite((void *)&Wfr, sizeof(Wfr), 1, wtp);
	fclose(wtp);

	printf("%s 작성 완료되었습니다.\n", filename);
	return 0;
}