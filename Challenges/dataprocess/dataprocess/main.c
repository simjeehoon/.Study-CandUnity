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
		printf("\n\n***********************\n" "�ɼ� ����\n1. �б�\n2. ����\n3. ����\n��ȣ �Է�: ");
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