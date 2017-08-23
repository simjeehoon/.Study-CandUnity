#include <stdio.h>

static void bufferreset()
{
	int a;
	while (1) {
		a = getchar();
		if (a == '\0' || a == '\n')
			break;
	}
}

int yunm210202() {
	char str1[20];
	char str2[20];
	char str3[40] = { 0 };
	
	bufferreset();
	printf("첫번째 문자열 : ");

//	fgets(str1, sizeof(str1), stdin);
	gets(str1, sizeof(str1));
	printf("두번째 문자열 : ");

//	fgets(str2, sizeof(str2), stdin);
	
	strcpy(str3, str1);


	printf("1.%s끝\n2.%s끝\n", str1, str2);
	printf("1[0] = %d 1[1] = %d 1[2] = %d\n", str1[0], str1[1], str1[2]);
	printf("2[0] = %d 2[1] = %d 2[2] = %d\n", str2[0], str2[1], str2[2]);
	return 0;
}