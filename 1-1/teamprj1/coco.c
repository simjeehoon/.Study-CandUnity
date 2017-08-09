#include <stdio.h>

int main(void)
{
	int op1;

	printf(">> 영타쳐보자! 아싸 <<\n");          //메인 화면
	printf("1. 자리나 연습해    2. 낱말 연습\n");
	printf("3. 짧은 글 연습     4. 아주 긴 글 연습\n");
	printf("5. 프로그램 종료\n\n");
	printf("번호를 선택하세요 : ");
	scanf("%d", &op1);

	switch(op1)                      //옵션 선택 화면
	{
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 5 : 
			break;
	}	

	return 0;
}
