#include <stdio.h>

#define N 21

int main(void)
{
	char name[N] = "";
	int i, c;

	printf("이름을 입력하세요 : \n");
	i = 0;
	while (1) {
		c = getchar();
		if((c == ' ') || (i == N)) {
			while((c = getchar()) != '\n')
				;
			for(i=0;i<N;i++)
				name[i] = '\0';
			printf("이름을 다시 입력하세요 : ");
			i=0;
			continue;
		}
		if (c==10)
			break;
		name[i++]=c;
	}
	printf("%s", name);
	return 0;
}
