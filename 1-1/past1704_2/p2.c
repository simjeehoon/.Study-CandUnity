#include <stdio.h>
int main(void)
{
	// 평년윤년 예제
	unsigned year;
	_Bool check;
	
	printf("enter year : \n");
	scanf("%d", &year);

	if(year % 4)
		check = 0;
	else if(year % 100)
		check = 1;
	else if(year % 400)
		check = 0;
	else
		check = 1;

	
	if(check)
		printf("%d년은 윤년입니다.\n", year);
	else
		printf("%d년은 평년입니다.\n", year);
	
	return 0;
}

