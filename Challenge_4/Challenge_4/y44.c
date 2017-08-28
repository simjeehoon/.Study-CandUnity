#include <stdio.h>

int y44()
{
	FILE * fp = fopen("text.txt", "rt");
	char word[100] = { 0 };
	int Aw = 0;
	int Pw = 0;
	if (fp == NULL) {
		printf("실패\n");
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
	printf("A로 시작하는 단어의 수 : %d\n", Aw);
	printf("P로 시작하는 단어의 수 : %d\n", Pw);
	fclose(fp);

	return 0;
}