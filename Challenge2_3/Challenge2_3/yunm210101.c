#include <stdio.h>
static void deletebuffer() {
	while (getchar() != '\n')
		;
}
int yunm210101() {
	int alphabet;
	int i;
	deletebuffer();

	printf("���ĺ��� �Է��Ͻÿ� : ");
	alphabet = getchar();
	
	if ('A' <= alphabet && alphabet <= 'Z')
	{
		i = alphabet - 'A';
		alphabet = 'a' + i;
		putchar(alphabet);
	}
	else if ('a' <= alphabet && alphabet <= 'z')
	{
		i = alphabet - 'a';
		alphabet = 'A' + i;
		putchar(alphabet);
	}
	else
	{
		printf("It is not alphabet\n");
	}
	return 0;
}