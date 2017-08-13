#include <stdio.h>
#include <termios.h>

int main(void)
{
	int m;

	while ((m = getch()) != 27)
		putch(m);

	return 0;
}
