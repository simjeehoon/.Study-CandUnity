#include "main.h"

int yunm160103() {
	int arr[5][5] = { 0 };
	int i, j;
	char * name[4] = { "ö��", "ö��", "����", "����" };
	char * subject[4] = { "����", "����", "����", "����" };
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			printf("%s�� %s ���� ���� �Է� : ", name[i], subject[j]);
			scanf("%d", &arr[i][j]);
		}
	printf("            ");
	for (i = 0; i < 4; i++)
		printf("%s ", subject[i]);
	printf("����\n");

	for (i = 0; i < 4; i++) {
		printf("%11s ", name[i]);
		for (j = 0; j < 4; j++) {
			printf("%4d ", arr[i][j]);
			arr[i][4] += arr[i][j];
		}
		printf("%4d ", arr[i][j]);
		printf("\n");
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			arr[4][i] += arr[j][i];
	}
	for (i = 0; i < 4; i++)
		arr[4][4] += arr[4][i];
	printf("���� ���� ");
	for (i = 0; i < 5; i++)
		printf("%4d ", arr[4][i]);
	printf("\n");
	return 0;
}