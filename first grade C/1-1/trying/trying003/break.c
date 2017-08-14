#include <stdio.h>

int main(void)
{
	int i;
	for(;;i++){
		if(i==100)
			break;
	}
	printf("%d번 째에 무한루프 탈출\n", i);
	return 0;
}


