#include "main.h"

int yunm160103() {
	int arr[5][5] = { 0 };
	int i, j;
	char * name[4] = { "철희", "철수", "영희", "영수" };
	char * subject[4] = { "국어", "영어", "수학", "국사" };
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			printf("%s의 %s 과목 성적 입력 : ", name[i], subject[j]);
			scanf("%d", &arr[i][j]);
		}
	printf("            ");
	for (i = 0; i < 4; i++)
		printf("%s ", subject[i]);
	printf("총점\n");

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
	printf("과목별 총점 ");
	for (i = 0; i < 5; i++)
		printf("%4d ", arr[4][i]);
	printf("\n");
	return 0;
}