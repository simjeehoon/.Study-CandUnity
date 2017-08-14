#include <stdio.h>

int main(void)
{
	int opt;
	int n, m;

	while(1)
	{
		printf("1. Add\n2. Sub\n3. Mul\n4. Div\n5. Exit\n");
		printf("명령을 입력하세요 : ");
		scanf("%d", &opt);
		
			if(opt==5)
				break;

		printf("두 수를 입력하세요 : ");
		scanf("%d%d", &n, &m);

			if(opt==1)
				printf("결과는 %d 입니다.\n", n+m);
				
			if(opt==2)
				printf("결과는 %d 입니다.\n", n-m);

			if(opt==3)
				printf("결과는 %d 입니다.\n", n*m);

			if(opt==4)
				printf("결과는 %d 입니다.\n", n/m);


		}
	return 0;
}
