#include "main.h"

int test01()
{
	int num;
	printf("%d\n", num);
	scanf("%d", &num);

	return 0;
}

void running(int(*munje)()) {
	int error = munje();
	if (error) 
		printf("\n"
			"*******************************************" 
			"\nError : �Լ��� ������������ ����Ǿ����ϴ�.\n"
			"*******************************************" 
			"\n");
}

int clear() {
	system("clear");
	return 0;
}