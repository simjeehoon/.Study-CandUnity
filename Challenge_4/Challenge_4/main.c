#include <stdio.h>
#include "main.h"
#include "virtual effect.h"
#define M(X) ym ## X

void func(int(*function) (void))
{
	SetColor(green);
	printf("\n** Function execute **\n");
	NormalColor();
	if (function()) {
		SetColor(red);
		printf("** Error : Function terminated abnormally **\n");
		SetColor(green);
	}
	else
	{
		SetColor(green);
		printf("** Function terminated. **\n");
	}
	printf("--------------------- main function --------------------- \n");
}


int main(void)
{
	int op;
	SetColor(green);
	printf("--------------------- main function --------------------- \n");
	while (1)
	{
		SetColor(light_green);
		printf("Option code : [-1 : Exit] [-2, -3 : Test Func]");
		SetColor(mint);
		printf(" < ## 도전 과제 > < #### 예제 > < # 기타 > \n");
		SetColor(real_white);
		printf("Input the code: ");
		scanf("%d", &op);
		getchar();

		switch (op)
		{
		case 1:
			func(N1);
			break;
		case 41:
			func(y41);
			break;
		case 2521:
			func(M(2521));
			break;
		case 2522:
			func(M(2522));
			break;
		case 2611:
			func(M(2611));
			break;
		case -1 :
			SetColor(green);
			printf("** Exit **\n");
			NormalColor();
			return 0;
			break;
		case -2 :
			func(test2);
			break;
		case -3:
			func(test3);
			break;
		default:
			SetColor(red);
			printf("** Error : Invalid code **\n\n");
			break;
		}
	}
	return 0;
}