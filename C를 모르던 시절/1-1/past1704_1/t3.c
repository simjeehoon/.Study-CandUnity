#include <stdio.h>

int main(void)
{
	char in;


	scanf("%c", &in);
//	printf("당신은 %c를 입력했어요(%d)\n", in, in); // 일단 확인

	if(65 <= in && in <= 90)
		printf("%c는 대문자입니다.\n", in);
	else if(97 <= in && in <= 122)
		printf("%c는 소문자입니다.\n", in);
	else if(48 <= in && in <= 57)
		printf("%c는 숫자입니다.\n", in);
	else
		printf("%c는 기타문자입니다.\n", in);

	return 0;
}

