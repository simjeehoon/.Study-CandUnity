#include <stdio.h>

int main(void)
{
	int op;

	while(op != 5)
	{
		printf(">> 영문 타자 연습 프로그램 <<\n");          //메인 화면
		printf("1. 자리 연습        2. 낱말 연습\n");
		printf("3. 짧은 글 연습     4. 긴 글 연습\n");
		printf("5. 프로그램 종료\n\n");
		printf("번호를 선택하세요 : ");
		scanf("%d", &op);

	switch(op)                      //옵션 선택 화면
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
			default : 
				printf("숫자를 잘못 입력하셨습니다.\n");
		}		
    }
	return 0;
}
