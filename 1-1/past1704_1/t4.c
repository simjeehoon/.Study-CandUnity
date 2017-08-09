#include <stdio.h>

int main(void)
{
	int n, d;
	double result;
	_Bool isd;

	printf("분자와 분모를 입력하세요 : ");
	scanf("%d %d",&n, &d);

	isd = (d==0)?1:0;

	if(isd)
		printf("0으로 나눌수없다.\n");

	else{
		result = (double) n / d;
		printf("결과 : %f\n", result);
	}
	return 0;
}

	

