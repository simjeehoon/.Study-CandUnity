#include <stdio.h>

long what_is_bite(FILE * file) {
	long curpos;
	long length;
	curpos = ftell(file);
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, curpos, SEEK_SET);
	return length;
}

int main()
{
	char buf[100];
	FILE * fp = fopen("aaa1.txt", "rt");
	if (fp == NULL)
		return -1;
	printf("���� ����Ʈ ũ�� : %ld\n", what_is_bite(fp));
	fgets(buf, sizeof(buf), fp);
	fputs(buf, stdout);
	printf("���� ����Ʈ ũ�� : %ld\n", what_is_bite(fp));
	fgets(buf, sizeof(buf), fp);
	fputs(buf, stdout);
	printf("���� ����Ʈ ũ�� : %ld\n", what_is_bite(fp));
	
	return 0;
}