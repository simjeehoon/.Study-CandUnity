#include <stdio.h>

int read();
int write();

void bufferreset() {
	int ch;
	while (1) {
		ch = getchar();
		if (ch == ' ' || ch == '\n')
			break;
	}
}

int main(void)
{
	int num;

	while (1)
	{
		printf("\n\n***********************\n" "옵션 선택\n1. 읽기\n2. 쓰기\n3. 종료\n번호 입력: ");
		scanf("%d", &num);
		bufferreset();
		if (num == 1)
			if(read())
				printf("Read Error\n");
		if (num == 2)
			if (write())
				printf("Write Error\n");
		if (num == 3)
			break;
	}

	return 0;
}