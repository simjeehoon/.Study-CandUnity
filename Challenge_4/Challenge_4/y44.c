#include <stdio.h>

int y44()
{
	FILE * fp = fopen("text.txt", "rt");
	char word[100] = { 0 };
	int Aw = 0;
	int Pw = 0;
	if (fp == NULL) {
		printf("����\n");
		return -1;
	}
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s", word);
		if (word[0] == 'A')
			Aw++;
		if (word[0] == 'P')
			Pw++;
	}
	printf("A�� �����ϴ� �ܾ��� �� : %d\n", Aw);
	printf("P�� �����ϴ� �ܾ��� �� : %d\n", Pw);
	fclose(fp);

	return 0;
}