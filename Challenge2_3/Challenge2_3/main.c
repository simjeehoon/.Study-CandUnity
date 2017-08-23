#include "main.h"



int main(int argc, char *argv[])
{
	int code = 0;
	int endcode = 0;
	
	int (*testfunction)() = test01;

	printf("받은 문자열 수 : %d \n", argc);
	for (int i = 0; i < argc; i++)
		printf("%d : %s\n", i, argv[i]);

	while (1)
	{
		printf("\n[exitcode: -1] [testcode: -2]\ninput code:");
		scanf("%d", &code);
		printf("\n");
		switch (code)
		{
		case 203:
			running(yun203);
			break;
		case 204:
			running(yun204);
			break;
		case 205:
			running(yun205);
			break;
		case 301:
			running(yun301);
			break;
		case 302:
			running(yun302);
			break;
		case 304:
			running(yun304);
			break;
		case 305:
			running(yun305);
			break;
		case 306:
			running(yun306);
			break;
		case 140101:
			running(yunm140101);
			break;
		case 140102:
			running(yunm140102);
			break;
		case 160101:
			running(yunm160101);
			break;
		case 160102:
			running(yunm160102);
			break;
		case 160103:
			running(yunm160103);
			break;
		case 170101:
			running(yunm170101);
			break;
		case 180101:
			running(yunm180101);
			break;
		case 210101:
			running(yunm210101);
			break;
		case 210201:
			running(yunm210201);
			break;
		case 210202:
			running(yunm210202);
			break;
		case 210203:
			running(yunm210203);
			break;
		case -1:
			return 0;
			break;
		case -2:
			running(testfunction);
			break;
		case -3:
			running(clear);
			break;
		default:
			printf("Error : invaild code.\n");
			break;
		}
	}
}