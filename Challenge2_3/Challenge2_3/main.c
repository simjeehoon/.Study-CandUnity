#include "main.h"



int main(void)
{
	int code = 0;
	int endcode = 0;

	while (1)
	{
		if (endcode) printf("\n비정상적인 종료\n");
		printf("\n[exitcode: -1]\ninput code:");
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
		case -1:
			return 0;
			break;
		default:
			printf("Error invaild code.\n");
			break;
		}
	}
}