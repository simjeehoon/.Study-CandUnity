#include <stdio.h>
#include <time.h>

int main(void)
{
	double result;
	time_t start, end;

	printf("시작\n");
	scanf("%f", &result);
	time(&start);

	printf("끝\n");
	scanf("%f", &result);
	time(&end);

	result = difftime(end, start);

	printf("시작과 끝 간의 시간 : %f", result);
	return 0;
}
