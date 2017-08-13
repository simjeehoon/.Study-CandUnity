#include <stdio.h>

int main(void)
{
	int year;
	_Bool isyear;

	printf("연도 : ");
	scanf("%d", &year);

	isyear = (year % 4) ? 0 : ((year % 100) ? 1 : ((year % 400) ? 0 : 1));

	if(isyear)
		printf(" %d년은 윤년입니다.\n", year);
	else
		printf(" %d년은 평년입니다.\n", year);

	return 0;
}

