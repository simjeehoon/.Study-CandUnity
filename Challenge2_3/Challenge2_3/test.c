#include "main.h"

int test01()
{
	printf("%d", atoi("으12"));
	return 0;
}

void running(int(*munje)()) {
	int error = munje();
	if (error) 
		printf("\n"
			"*******************************************" 
			"\nError : 함수가 비정상적으로 종료되었습니다.\n"
			"*******************************************" 
			"\n");
}

int clear() {
	system("clear");
	return 0;
}