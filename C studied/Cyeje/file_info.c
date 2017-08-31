#include <stdio.h>

int main(void)
{
	int c, total_byte = 0, line = 0;
	while((c=getchar()) != EOF){
		total_byte++;
		if(c == '\n')
			line++;
	}
	printf("파일 크기 : %d바이트\n", total_byte);
	printf("파일 줄 수 : %d줄\n", line);
	return 0;
}
