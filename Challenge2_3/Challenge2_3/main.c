#include "main.h"



int main(void)
{
	int code = 0;
	int endcode = 0;

	while (1)
	{
		if (endcode) printf("\n비정상적인 종료\n");
		printf("\n[exitcode: -1] [testcode: -2]\ninput code:");
		scanf("%d", &code);
		printf("\n");
		switch (code)
		{
		case 203:
			endcode = yun203();
			break;
		case 204:
			endcode = yun204();
			break;
		case 205:
			endcode = yun205();
			break;
		case 301:
			endcode = yun301();
			break;
		case 302:
			endcode = yun302();
			break;
		case 304:
			endcode = yun304();
			break;
		case 305:
			endcode = yun305();
			break;
		case 306:
			endcode = yun306();
			break;
		case 140101:
			endcode = yunm140101();
			break;
		case 140102:
			endcode = yunm140102();
			break;
		case 160101:
			endcode = yunm160101();
			break;
		case 160102:
			endcode = yunm160102();
			break;
		case 160103:
			endcode = yunm160103();
			break;
		case 170101:
			endcode = yunm170101();
			break;
		case -1:
			return 0;
			break;
		case -2:
			endcode = test01();
			break;
		default:
			printf("Error : invaild code.\n");
			break;
		}
	}
}