#include <stdio.h>
#include <termio.h>
#include <time.h>

int getch(void)
{
	int res;
	struct termios buf, storage;
	tcgetattr(0,&storage);
	buf = storage;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	res = getchar();
	tcsetattr(0, TCSAFLUSH, &storage);
	return res;
}

int main(void)
{
	char alpha;
		while (1)
		{
			//alpha = getch();
			//printf("%c,%d\n",alpha, alpha);
			if (alpha == 8) // 백스페이스 누르면
				printf("%b");
			else 
				printf("%c", alpha);
		}
		return 0;
}
