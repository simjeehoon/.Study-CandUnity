#include <stdio.h>
#include <stdbool.h>

int y45()
{
	FILE * d1 = fopen("d1.txt", "rt");
	FILE * d2 = fopen("d2.txt", "rt");
	int ch1;
	int ch2;
	_Bool same = false;

	if (d1 == NULL || d2 == NULL) {
		printf("����\n");
		return -1;
	}

	while (1)
	{
		if (fgetc(d1) != fgetc(d2))
			break;

		if (feof(d1) != 0) {
			if (feof(d2) != 0) {
				same = true;
				break;
			}
			else
				break;
		}

		if (feof(d2) != 0) {
				break;
		}
	}
	if (same) printf("�� ���� ������ ������ ��ġ �մϴ�.\n");
	else printf("���� �ٸ� �����Դϴ�.\n");
	fclose(d1);
	fclose(d2);
	return 0;
}