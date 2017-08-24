#include <stdio.h>

void bufferreset()
{
	int a;
	while (1) {
		a = getchar();
		if (a == '\0' || a == '\n')
			break;
	}
}

static void enter_remove(char * str) {
	int length = strlen(str);
	str[length - 1] = '\0';
}

int yunm210202() {
	char str1[20];
	char str2[20];
	char str3[40] = { 0 };
	int i;
	
	bufferreset();
	printf("첫번째 문자열 : ");

	fgets(str1, sizeof(str1), stdin);
//	gets(str1, sizeof(str1));
	printf("두번째 문자열 : ");

	fgets(str2, sizeof(str2), stdin);
//	gets(str2, sizeof(str2));
	enter_remove(str1);
	enter_remove(str2);
	strcpy(str3, str1);
	strcat(str3, str2);
	printf("문자열 :\n%s끝\n", str3);

	return 0;
}