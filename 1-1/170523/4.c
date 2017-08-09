#include <stdio.h>

int main(void)
{
	static int a= 0;
	printf("끝나지 않는 재귀함수...\n");
	a++;
	if(a<5)
		main();
	return 0;
}

