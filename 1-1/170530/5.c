#include <stdio.h>
#include <termio.h>
int getch(void){
	int ch;

	struct termios buf;
	struct termios save;

	tcgetattr(0, &save);
	buf = save;

	buf.c_lflag&=~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;

	tcsetattr(0, TCSAFLUSH, &buf);

	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);

	return ch;
}

int main(void){
	int input_char;
	int i=0, j=0;

	while(1){
		input_char = getch();
		if (input_char == 'g')
			i++;
		j++;
		if (j == 10)
			break;
	}

	printf("\'g\' 입력 횟수 : %d번\n", i);
	printf("빈도 : %.1f", i / (double)j);

	return 0;
}

