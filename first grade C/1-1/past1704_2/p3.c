#include <stdio.h>

int main(void)
{
	int grade;
	printf("점수는 ? : ");
	scanf("%d", &grade);	

	if(0 <= grade && grade <= 100)
	{
	   	if(grade > 60)
			printf("당신은 합격입니다.\n");
		else
			printf("당신은 불합격입니다.\n");
	}
	else
		printf("잘못된 점수입니다.\n");
	return 0;
}


