#include <stdio.h>

int main(void)
{
	int year;
	
	printf("연도입력 : ");
	scanf("%d", &year);

	if(year % 4)
		printf("%d년은 평년입니다.\n", year);
	else if(year % 100)
		printf("%d년은 윤년입니다.\n", year);
	else if(year % 400)
		printf("%d년은 평년입니다.\n", year);
	else
		printf("%d년은 윤년입니다.\n", year);

	return 0;
}


